// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Server.h"

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

Communicators::rPtr __response_function = [](Data::IContainer request)
{
    auto client_request = Create::ClientRequest(request);
    // TODO

    auto result = Data::Result::New(true);
    auto status = Data::Status::New(10, 10, 10, 10);
    auto animation = Data::Animation::New();
    auto response = Create::ServerResponse(std::move(status), std::move(animation), std::move(result));

    return response->Serialize();
};

Server::Server::Server()
{
    this->responder = std::make_unique<Communicators::TcpHost>(Communicators::TcpHost(__response_function));
}

void Server::Server::Start()
{
    this->responder->Start();
}

bool Server::Server::getIsRunning()
{
    return this->responder->getIsRunning();
}

void Server::Server::Stop()
{
    return this->responder->Stop();
}

