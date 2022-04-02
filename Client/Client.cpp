// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include "Client.h"



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


Client::Client::Client()
{
	Data::IPV4Address localhost = { 127, 0, 0, 1 };
	this->remote = Create::RemoteTcpServer(localhost);

}

Client::Client::Client(std::unique_ptr<Communicators::IRemoteResponder> remote)
	: remote(std::move(remote))
{

}

inline void Client::Client::__setResponseParser(ResponseParser rp) {
	this->response_parser = rp;
}

std::unique_ptr<Data::IServerResponse> Client::Client::SendCommand(std::unique_ptr<Data::IClientRequest> request)
{
    return std::nullptr_t();
}
