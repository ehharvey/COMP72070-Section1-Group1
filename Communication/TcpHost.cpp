#pragma once
#include <iostream>
#include <optional>
#include "TcpHost.h"

std::optional<SOCKET> create_server_socket() {
	//starts Winsock DLLs		
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cerr << "WSAStartup Failed.";
		return {};
	}
		

	//create server socket
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		std::cerr << "ServerSocket Creation Failed.";
		return {};

	}

	//binds socket to address
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(27000);
	if (bind(ServerSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		std::cerr << "ServerSocket Binding Failed.";
		return {};
	}

	return ServerSocket;
}

// Receives a server socket and waits for a connection
// Upon receiving a connection, returns socket to it
std::optional<SOCKET> listen_for_connection(SOCKET ServerSocket) {
	//listen on a socket
	if (listen(ServerSocket, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		std::cerr << "Listen on Socket Failed.";
		return {};
	}

	//accepts a connection from a client
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	std::cout << "Awaiting client...";
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		std::cerr << "Accepting Connection from Client Failed.";
		return {};
	}
	std::cout << "Connection established.\n";
	return ConnectionSocket;
}

void __start_helper(SOCKET server_socket, Communicators::rPtr response_function)
{
	//listen on a socket
	if (listen(server_socket, 1) == SOCKET_ERROR) {
		closesocket(server_socket);
		WSACleanup();
		std::cerr << "Listen on Socket Failed.";
		return;
	}

	//accepts a connection from a client
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	std::cout << "Awaiting client...";
	if ((ConnectionSocket = accept(server_socket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(server_socket);
		WSACleanup();
		std::cerr << "Accepting Connection from Client Failed.";
	}
	std::cout << "Connection established.\n";

	if (true)
	{
		Data::IContainer client_request_serialization;
		bool more_transmissions_incoming;

		do
		{
			Data::Transmission received_transmission;

			// Issue is here #35
			recv(ConnectionSocket, (char*)&(received_transmission.header), sizeof(received_transmission.header), 0);
			more_transmissions_incoming = received_transmission.header.more_incoming != 0x0;

			recv(ConnectionSocket, (char*) &received_transmission.data.front(), received_transmission.header.transmit_size, 0);

			auto data_end = received_transmission.data.begin();
			std::advance(data_end, received_transmission.header.transmit_size);

			std::copy(received_transmission.data.begin(), data_end,
				std::back_insert_iterator(client_request_serialization));
		} while(more_transmissions_incoming);
			
		auto response = response_function(client_request_serialization);

		auto remaining_size = response.size();
		auto copy_start = response.begin();
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

			send(ConnectionSocket, (const char *) &new_transmission.header, sizeof(new_transmission.header), 0);

			auto end = copy_start;
			std::advance(end, copy_size);
			std::copy(copy_start, end, new_transmission.data.begin());
				
			send(ConnectionSocket, (const char *) &new_transmission.data.front(), copy_size, 0);

			remaining_size -= copy_size;
			copy_start = end;
			closesocket(ConnectionSocket);
		}
	}
}

Communicators::TcpHost::TcpHost(rPtr response_function) :
	response_function(response_function)
{ 
	auto server_socket_attempt = create_server_socket();
	if (server_socket_attempt.has_value())
	{
		this->server_socket = server_socket_attempt.value();
		this->running_thread = std::thread();
	}
	else
	{
		std::cerr << "TcpHost: Unable to create server socket!\n";
		this->server_socket = SOCKET_ERROR;
	}
};

void Communicators::TcpHost::Start()
{
	__start_helper(this->server_socket, this->response_function);
}