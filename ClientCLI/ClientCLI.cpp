// ClientCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CLI.h"
#include "..\Client\Client.h"
#include "..\Communication\Communication.h"
#include "..\Logger\Logger.h"
#include "..\Server\Server.h"
#include "..\Tamagotchi\Tamagotchi.h"

int main()
{
    cout << "Tamagotchi [Version 1.0] \n";
    cout << "COMP72070. Group #1\n\n";

    bool Quit = false;

    string userInput;

    while (!Quit)
    {
        hashit();
        cout << "\Tamagotchi> ";
        cin >> userInput;

        string command;
        string amount;

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

            Quit = true;
            break;
        }
        }
    }
    return 0;
}