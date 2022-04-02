// ClientCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "ClientCLI.h"




void app(istream& input, ostream& output)
{
    output << "Tamagotchi [Version 1.0] \n";
    output << "COMP72070. Group #1\n\n";

    bool Quit = false;

    string userInput;

    string command; // e.g Feed, Clean
    string amount;  // e.g '20'

    queue<string> commands; // if userInput = 'l'

    while (!Quit)
    {
        hashit();
        output << "Tamagotchi> ";
        input >> userInput;

        if (userInput == "l")
        {
            // Add code to change state to QUEUE

        }

        // Split string (Command, value)
        for (int i = 0; i < userInput.length(); i++)
        {
            if (userInput[i] == ' ')
            {
                command.append(userInput.substr(0, i));
                amount.append(userInput.substr(i + 1, userInput.length() - 1));
                break;
            }
        }

        switch (string_commands[userInput])
        {
        case eFeed:
        {
            break;
        }
        case eSleep:
        {
            break;
        }
        case eClean:
        {
            break;
        }
        case eHelp:
        {
            help();
            break;
        }

        case QUIT:
        {
            output << "Goodbye!";
            // Add code to delete queue if in QUEUE state
            Quit = true;
            break;
        }
        }
    }
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