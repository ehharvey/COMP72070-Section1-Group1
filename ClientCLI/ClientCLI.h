#pragma once
#include "..\Communication\Create.h"
#include "..\Logger\Create.h"
#include "..\Server\Create.h"
#include "..\Tamagotchi\Create.h"
#include "..\Client\Create.h"
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

enum string_command {

	eFeed,
	eSleep,
	eClean,
	eHelp,
	QUEUE, //?
	QUIT,
};
map<string, string_command> string_commands;

void hashit() // Map user input to command
{
	string_commands["feed"] = eFeed;
	string_commands["Feed"] = eFeed;
	string_commands["sleep"] = eSleep;
	string_commands["Sleep"] = eSleep;
	string_commands["clean"] = eClean;
	string_commands["Clean"] = eClean;
	string_commands["help"] = eHelp;
	string_commands["Help"] = eHelp;
	string_commands["Quit"] = QUIT;
	string_commands["quit"] = QUIT;
	string_commands["q"] = QUIT;
	string_commands["Q"] = QUIT;
	string_commands["Exit"] = QUIT;
	string_commands["exit"] = QUIT;
}

void help()
{
	cout << "List of commands:" << endl;
	cout << "Feed" << endl;
	cout << "Sleep" << endl;
	cout << "Clean" << endl;
	cout << "Help" << endl;
	cout << "l (Queue)" << endl;
	cout << "Quit\n" << endl;
	
	cout << "Example: 'Feed 20'\n" << endl;
}