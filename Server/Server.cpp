#include <iostream>
#include <fstream>
#include <bitset>
#include "Server.h"

auto tamagotchi = Create::Tamagotchi();

std::string Server::getAuthorizationString(uint8_t authbyte)
{
    return std::bitset< 8 >(authbyte).to_string();
}

Communicators::rPtr __response_function = [](Data::IContainer request)
{
    auto client_request = Create::ClientRequest(request);

    if (client_request->getAuthorization().getAuthByte() == tamagotchi->getAuthorization().getAuthByte())
    {
        auto command = client_request->getCommand().getAction();
        if (command == Data::CommandAction::quit)
        {
            std::cout << "Quit command received... Stopping server!" << std::endl;
            WSACleanup();
            exit(0);
        }
        else if (command == Data::CommandAction::music)
        {
            auto music = Data::Music::New();
            auto response = Create::ServerResponse(std::move(music));
            return response->Serialize();
        }
        else
        {
            auto result = Data::Result::New(true);
            tamagotchi->AddCommand(client_request->getCommand().getAction());
            auto status = tamagotchi->getStatusCopy();
            auto command = tamagotchi->GetCurrentCommand();
            auto response = Create::ServerResponse(std::move(status), std::move(command), std::move(result));
            return response->Serialize();
        }
    }
    else
    {
        auto result = Data::Result::New(false);
        auto response = Create::ServerResponse(std::move(result));
        return response->Serialize();
    }
};


Server::Server::Server()
{
    std::cout << "Use this authorization code: " << getAuthorizationString(tamagotchi->getAuthorization().getAuthByte()) << std::endl;
    this->responder = std::make_unique<Communicators::TcpHost>(Communicators::TcpHost(__response_function));
}

void Server::Server::setShouldContinue(bool b)
{
    this->should_continue = b;
}

void Server::Server::Start()
{   
    this->should_continue = true;
    while (should_continue)
    {
        this->responder->Start();
    }
}

