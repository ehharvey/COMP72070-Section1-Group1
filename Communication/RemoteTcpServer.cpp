#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma once
#include "RemoteTcpServer.h"

#include <optional>
#include <iostream>

// Helper functions
// Self explanatory
std::optional<SOCKET> initialize_client_socket() {

	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		std::cerr << "Unable to initialize Winsock DLLs";
		return {};
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		std::cerr << "Unable to initialize Client Socket";
		return {};
	}

	return ClientSocket;
}

// Connects to to a server, after which ClientSocket is ready
// to receive input via send()
bool connect_to_server(SOCKET ClientSocket, Data::IPV4Address remote) {
	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr(remote.ToString().c_str());	//IP address
	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		std::cerr << "Unable to connect to server.";
		return false;
	}
	else
	{
		return true;
	}
}


Data::IContainer send_payload(SOCKET ClientSocket, const Data::IContainer & payload) {
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

		send(ClientSocket, (const char *) &new_transmission.header, sizeof(new_transmission.header), 0);

		auto end = copy_start;
		std::advance(end, copy_size);
		std::copy(copy_start, end, new_transmission.data.begin());
		
		send(ClientSocket, (const char *) &new_transmission.data.front(), copy_size, 0);

		remaining_size -= copy_size;
		copy_start = end;
	}

	Data::IContainer result;

	bool continue_receiving;
	do
	{
		auto received_transmission = Data::Transmission();

		recv(ClientSocket, (char *) &received_transmission.header, sizeof(received_transmission.header), 0);
		continue_receiving = received_transmission.header.more_incoming != 0x0;

		recv(ClientSocket, (char*) &received_transmission.data.front(), received_transmission.header.transmit_size, 0);
		auto end = received_transmission.data.begin();
		std::advance(end, received_transmission.header.transmit_size);

		std::copy(received_transmission.data.begin(), end, std::back_inserter(result));

	} while (continue_receiving);

	return result;
}

Communicators::RemoteTcpServer::RemoteTcpServer(Data::IPV4Address address)
: address(address)
{
	auto client_socket_attempt = initialize_client_socket();
	if (client_socket_attempt.has_value())
	{
		this->client_socket = client_socket_attempt.value();
	}
	else
	{
		std::cerr << "RemoteTcpServer: Unable to initialize client socket!";
		this->client_socket = SOCKET_ERROR;
	}
}

Data::IContainer 
Communicators::RemoteTcpServer::GetResponse
(Data::IContainer request) const
{
	connect_to_server(this->client_socket, this->address);
	return send_payload(this->client_socket, request);
}

Communicators::RemoteTcpServer::~RemoteTcpServer()
{
	//frees Winsock DLL resources
	WSACleanup();
}