// ClientCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CLI.h"
#include "..\Client\Client.h"
#include "..\Communication\Communication.h"
#include "..\Logger\Logger.h"
#include "..\Server\Server.h"
#include "..\Tamagotchi\Tamagotchi.h"

// REQUIRED IMPLEMENTATIONS*
// Implement queue
// Integrate Log
// Implement Code corresponding to each switch case (Transmission of data)

int main()
{
    cout << "Tamagotchi [Version 1.0] \n";
    cout << "COMP72070. Group #1\n\n";

    bool Quit = false;

    string userInput;

    string command; // e.g Feed, Clean
    string amount;  // e.g '20'

    queue<string> commands; // if userInput = 'l'

    while (!Quit)
    {
        hashit();
        cout << "\Tamagotchi> ";
        cin >> userInput;

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
            cout << "Goodbye!";
            // Add code to delete queue if in QUEUE state
            Quit = true;
            break;
        }

        }
    }
    return 0;
}