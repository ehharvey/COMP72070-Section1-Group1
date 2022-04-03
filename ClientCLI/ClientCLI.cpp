// ClientCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <optional>
#include "ClientCLI.h"

std::optional<uint8_t> getAuthByte(std::string auth_str)
{
    if (auth_str.length() != 8)
    {
        cerr << "getAuthByte: parameter is of incorrect length. It should be 8 characters long" << endl;
        return {};
    }
    else
    {
        uint8_t result = 0;
        for (auto i = 0; i < auth_str.length(); i++)
        {
            char c = auth_str[i];

            switch(c)
            {
            case '0':
            {
                // Do nothing
                break;
            }
            case '1':
            {
                uint8_t insertee = 1 << (7 - i);
                result |= insertee;
                break;
            }
            default:
            {
                cerr << "getAuthByte: received nonbinary parmeter!\n";
                return {};
            }
            }
        }

        return result;
    }
}

void help()
{
	cout << "List of commands:" << endl;
	cout << "Feed" << endl;
	cout << "Sleep" << endl;
	cout << "Clean" << endl;
	cout << "Help" << endl;
	cout << "Send" << endl;
	cout << "Quit" << endl;
}

map<string, Data::CommandAction> getCommandMap() // Map user input to command
{
    map<string, Data::CommandAction> string_commands;
	string_commands["feed"] = Data::CommandAction::feed;
	string_commands["Feed"] = Data::CommandAction::feed;
	string_commands["sleep"] = Data::CommandAction::sleep;
	string_commands["Sleep"] = Data::CommandAction::sleep;
	string_commands["clean"] = Data::CommandAction::clean;
	string_commands["Clean"] = Data::CommandAction::clean;
	string_commands["help"] = Data::CommandAction::help;
	string_commands["Help"] = Data::CommandAction::help;
	string_commands["Quit"] = Data::CommandAction::quit;
	string_commands["quit"] = Data::CommandAction::quit;
	string_commands["q"] = Data::CommandAction::quit;
	string_commands["Q"] = Data::CommandAction::quit;
	string_commands["Exit"] = Data::CommandAction::quit;
	string_commands["exit"] = Data::CommandAction::quit;
    string_commands["send"] = Data::CommandAction::send;
    string_commands["Send"] = Data::CommandAction::send;

    return string_commands;
}


void app(istream& input, ostream& output)
{
    output << "Tamagotchi [Version 1.0] \n";
    output << "COMP72070 Group #1\n\n";

    auto client = Create::Client();

    std::vector<std::unique_ptr<Data::ClientRequest>> requests;

    string userInput;
    string command; // e.g Feed, Clean

    auto string_commands = getCommandMap();

    string auth;
    std::optional<uint8_t> auth_byte;
    do
    {
        output << "Enter authorization sequence (1s and 0s): ";
        input >> auth;
        auth_byte = getAuthByte(auth);
    } while (!auth_byte.has_value());
    

    output << "Type 'Help' for help\n";

    bool Quit;
    do
    {
        output << "Tamagotchi> ";
        input >> userInput;
        switch (string_commands[userInput])
        {
        case Data::CommandAction::feed:
        {
            requests.push_back(Create::ClientRequest(Data::Authorization::New(auth_byte.value()), Create::Command(Data::CommandAction::feed)));
            output << "Feed command added" << endl;
            break;
        }
        case Data::CommandAction::sleep:
        {
            requests.push_back(Create::ClientRequest(Data::Authorization::New(auth_byte.value()), Create::Command(Data::CommandAction::sleep)));
            output << "Sleep command added" << endl;
            break;
        }
        case Data::CommandAction::clean:
        {
            requests.push_back(Create::ClientRequest(Data::Authorization::New(auth_byte.value()), Create::Command(Data::CommandAction::clean)));
            output << "Clean command added" << endl;
            break;
        }
        case Data::CommandAction::help:
        {
            help();
            break;
        }
        case Data::CommandAction::send:
        {
            std::vector<std::unique_ptr<Data::IServerResponse>> responses;
            for (auto & r : requests)
            {
                responses.push_back(client->SendCommand(std::move(r)));
            }
            auto & last_response = responses.back();

            output << requests.size() << " commands sent" << endl;
            output << "Result:" << endl;
            output << "Authorization: " << (last_response->getResult().AuthSuccess() ? "Succcess" : "Failure") << endl;
            output << "Tamagotchi Status: " << endl;
            output << "\t" << "Happiness: " << last_response->getTamagotchiStatus().getHappiness() << "/" << Data::MAX_STAT_LEVEL << endl;
            output << "\t" << "Alertness: " << last_response->getTamagotchiStatus().getAlertness() << "/" << Data::MAX_STAT_LEVEL << endl;
            output << "\t" << "Cleaniness: " << last_response->getTamagotchiStatus().getCleaniness() << "/" << Data::MAX_STAT_LEVEL << endl;
            output << "\t" << "Stomach Level: " << last_response->getTamagotchiStatus().getStomachLevel() << "/" << Data::MAX_STAT_LEVEL << endl;

            responses.clear();
            requests.clear();
        }
        case Data::CommandAction::quit:
        {
            output << "Goodbye!";
            Quit = true;
            break;
        }
        default:
        {
            output << "ERROR: Invalid command. Enter 'Help' for possible commands" << endl;
        }
        }

        if (requests.size() > 0)
        {
            output << "There are " << requests.size() << " pending commands. Enter 'Send' to send them" << endl;
        }
    } while (!Quit);
}

// REQUIRED IMPLEMENTATIONS*
// Implement queue
// Integrate Log
// Implement Code corresponding to each switch case (Transmission of data)

int main()
{
    auto server = Server::Server();
    auto client = Client::Client::New();

    auto auth = Data::Authorization::New(5);
    auto command = Data::Command::New({ 1 });
    auto client_request = Create::ClientRequest(std::move(auth), std::move(command));

    server.Start();

    auto response = client->SendCommand(std::move(client_request));

    std::cout << response->getResult().AuthSuccess();

    //app(cin, cout);

    server.Stop();
    return 0;
}