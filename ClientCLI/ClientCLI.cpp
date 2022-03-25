// ClientCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\Client\Client.h"
#include "..\Communication\Communication.h"
#include "..\Logger\Logger.h"
#include "..\Server\Server.h"
#include "..\Tamagotchi\Tamagotchi.h"

int main()
{
    enum inputOptions {help, feed, clean, sleep, quit, invalid};
    
    bool continueCLI = true;

    do
    {
        //show menu
        //get input
            //update bool if necessary
        //parse digits if any
        //send command to server
        //show response

    } while (continueCLI);
    return 0;
}