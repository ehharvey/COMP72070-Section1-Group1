#include <iostream>
#include <fstream>
#include <bitset>
#include "Server.h"

std::string Server::getAuthorizationString(uint8_t authbyte)
{
    return std::bitset< 8 >(authbyte).to_string();
}


Server::Server::Server()
{
    Communicators::rPtr __response_function = [this](Data::IContainer request)
    {
        auto client_request = Create::ClientRequest(request);
        
        if (client_request->getAuthorization().getAuthByte() == this->tamagotchi->getAuthorization().getAuthByte())
        {
            auto command = client_request->getCommand().getAction();
            if (command == Data::CommandAction::quit)
            {
                std::cout << "Quit command received... Stopping server!" << std::endl;

                std::fstream tam_file;
                tam_file.open(this->tamagotchi_file_path);

                if (!tam_file.is_open())
                {
                    tam_file.clear();
                    tam_file.open(this->tamagotchi_file_path, std::ios::out);
                    tam_file.clear();
                    tam_file.open(this->tamagotchi_file_path);
                }

                for (auto b : this->tamagotchi->Serialize())
                {
                    tam_file << b;
                }

                tam_file.close();

                this->should_continue = false;
                auto result = Data::Result::New(false);
                auto response = Create::ServerResponse(std::move(result));
                return response->Serialize();
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
                this->tamagotchi->AddCommand(client_request->getCommand().getAction());
                auto status = this->tamagotchi->getStatusCopy();
                auto command = this->tamagotchi->GetCurrentCommand();
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

    this->tamagotchi_file_path = "tamagotchi";

    std::fstream tam_file;
    tam_file.open(tamagotchi_file_path);

    if (!tam_file.is_open())
    {
         tam_file.clear();
         tam_file.open(this->tamagotchi_file_path, std::ios::out);
         tam_file.clear();
         tam_file.open(this->tamagotchi_file_path);
    }

    Data::IContainer tam_serialization;

    while(!tam_file.eof())
    {
        tam_serialization.push_back((uint8_t) tam_file.get());
    }

    tam_file.close();

    auto tamagotchi_obj = Tamagotchi::Tamagotchi::Deserialize(tam_serialization);

    if (tamagotchi_obj.has_value())
    {
        std::cout << "Existing tamagotchi found!" << std::endl;
        this->tamagotchi = std::move(tamagotchi_obj).value();
    }
    else
    {
        std::cout << "Creating new tamagotchi!" << std::endl;;
        this->tamagotchi = Create::Tamagotchi();
    }

    std::cout << "Use this authorization code: " << getAuthorizationString(this->tamagotchi->getAuthorization().getAuthByte()) << std::endl;
    this->responder = std::make_unique<Communicators::TcpHost>(Communicators::TcpHost(__response_function));
}

void Server::Server::Start()
{   
    this->should_continue = true;
    while (should_continue)
    {
        this->responder->Start();
    }
}

