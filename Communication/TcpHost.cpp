#pragma once
#include <iostream>
#include <optional>
#include "TcpHost.h"

void __start_helper(Communicators::rPtr response_function)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, "2500", &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    // No longer need server socket
    closesocket(ListenSocket);

    Data::IContainer client_request_serialization;
    // Receive until the peer shuts down the connection
    bool more_transmissions_incoming;
    do {
        Data::Transmission received_transmission;
        iResult = recv(ClientSocket, (char*)&(received_transmission.header), sizeof(received_transmission.header), 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);

            more_transmissions_incoming = received_transmission.header.more_incoming != 0x0;

            iResult = recv(ClientSocket, (char*)&received_transmission.data.front(), received_transmission.header.transmit_size, 0);
            printf("Bytes received: %d\n", iResult);

            auto data_end = received_transmission.data.begin();
            std::advance(data_end, received_transmission.header.transmit_size);

            std::copy(received_transmission.data.begin(), data_end,
                std::back_insert_iterator(client_request_serialization));
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return;
        }
    } while (iResult > 0 && more_transmissions_incoming);

    std::cout << "Creating response...\n";
    auto response = response_function(client_request_serialization);

    auto remaining_size = response.size();
    auto copy_start = response.begin();
    while (remaining_size > 0)
    {
        std::cout << "Replying...\n";
        auto new_transmission = Data::Transmission();
        uint16_t copy_size = Data::MAX_PACKET_SIZE;

        if (remaining_size > Data::MAX_PACKET_SIZE)
        {
            copy_size = Data::MAX_PACKET_SIZE;
            new_transmission.header.more_incoming = 0x1;
        }
        else
        {
            copy_size = remaining_size;
            new_transmission.header.more_incoming = 0x0;
        }

        new_transmission.header.transmit_size = copy_size;

        iSendResult = send(ClientSocket, (const char*)&(new_transmission.header), sizeof(new_transmission.header), 0);

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return;
        }

        auto end = copy_start;
        std::advance(end, copy_size);
        std::copy(copy_start, end, new_transmission.data.begin());

        std::cout << "Copy size is " << copy_size << std::endl;

        iSendResult = send(ClientSocket, (const char*)&(new_transmission.data.front()), copy_size, 0);

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return;
        }

        remaining_size -= copy_size;
        copy_start = end;
    }

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();
}

Communicators::TcpHost::TcpHost(rPtr response_function) :
	response_function(response_function)
{ };

void Communicators::TcpHost::Start()
{
	__start_helper(this->response_function);
}