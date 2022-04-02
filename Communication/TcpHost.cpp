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
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		std::cerr << "Accepting Connection from Client Failed.";
		return {};
	}

	return ConnectionSocket;
}

void __start_helper(SOCKET server_socket, Communicators::rPtr response_function)
{
	while (true)
	{
		if (server_socket == SOCKET_ERROR)
		{
			std::cerr << "TcpHost: Socket seems to be closed... stopping listen\n";
			return;
		}
		auto received = listen_for_connection(server_socket);

		if (received.has_value())
		{
			Data::IContainer client_request_serialization;
			bool more_transmissions_incoming;

			do
			{
				Data::Transmission received_transmission;
				recv(received.value(), (char*)&received_transmission.header, sizeof(received_transmission.header), 0);
				more_transmissions_incoming = received_transmission.header.more_incoming != 0x0;

				recv(received.value(), (char*) &received_transmission.data.front(), received_transmission.header.transmit_size, 0);
				std::copy(received_transmission.data.begin(), received_transmission.data.end(),
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

				send(received.value(), (const char *) &new_transmission.header, sizeof(new_transmission.header), 0);

				auto end = copy_start;
				std::advance(end, copy_size);
				std::copy(copy_start, end, new_transmission.data.begin());
				
				send(received.value(), (const char *) &new_transmission.data.front(), copy_size, 0);

				remaining_size -= copy_size;
				copy_start = end;
			}
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
	// This starts the thread
	this->running_thread = std::thread(__start_helper, this->server_socket, this->response_function);
}

bool Communicators::TcpHost::getIsRunning()
{
	return this->running_thread.joinable();
}

void Communicators::TcpHost::Stop()
{
	// This may need to be atomic
	shutdown(this->server_socket, SD_BOTH);
	this->server_socket = SOCKET_ERROR;
	this->running_thread.join();
}