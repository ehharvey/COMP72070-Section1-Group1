#define WIN32_LEAN_AND_MEAN
#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#include "RemoteTcpServer.h"

#include <optional>
#include <iostream>

// Helper functions
// Self explanatory

// Connects to to a server, after which ClientSocket is ready
// to receive input via send()

Data::IContainer send_payload(const Data::IContainer & payload) {
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;
    int iResult;


    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return {};
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo("127.0.0.1", "2500", &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return {};
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return {};
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return {};
    }

    auto remaining_size = payload.size();
    auto copy_start = payload.begin();
    while (remaining_size > 0)
    {
        auto new_transmission = Data::Transmission();
        auto copy_size = Data::MAX_PACKET_SIZE;

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

        iResult = send(ConnectSocket, (const char*)&new_transmission.header, sizeof(new_transmission.header), 0);

        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return {};
        }

        auto end = copy_start;
        std::advance(end, copy_size);
        std::copy(copy_start, end, new_transmission.data.begin());

        iResult = send(ConnectSocket, (const char*)&new_transmission.data.front(), copy_size, 0);

        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return {};
        }

        remaining_size -= copy_size;
        copy_start = end;
    }

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return {};
    }

    // Receive until the peer closes the connection
    Data::IContainer result_serialization;
    bool continue_receiving;
    auto received_transmission = new Data::Transmission();
    do {
        iResult = recv(ConnectSocket, (char*)&received_transmission->header, sizeof(received_transmission->header), 0);
        if (iResult == 0)
            printf("Connection closed\n");

        
        continue_receiving = received_transmission->header.more_incoming != 0x0;

        iResult = recv(ConnectSocket, (char*)&(received_transmission->data.front()), received_transmission->header.transmit_size, 0);
        
        auto end_ptr = received_transmission->data.begin();
        std::advance(end_ptr, received_transmission->header.transmit_size);

        std::copy(received_transmission->data.begin(), end_ptr, std::back_inserter(result_serialization));
    } while (iResult > 0 && continue_receiving);
    delete received_transmission;
    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();
	return result_serialization;
}

Communicators::RemoteTcpServer::RemoteTcpServer(Data::IPV4Address address)
: address(address)
{ }

Data::IContainer 
Communicators::RemoteTcpServer::GetResponse
(Data::IContainer request) const
{
	return send_payload(request);
}

Communicators::RemoteTcpServer::~RemoteTcpServer()
{
	//frees Winsock DLL resources
	WSACleanup();
}