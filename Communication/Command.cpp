#pragma once
#include <map>
#include "Command.h"

Data::Command::Command()
: command_action(idle)
{ }

Data::Command::Command(Data::IContainer Serialization)
{
	switch (Serialization.size())
	{
	case 0:
		std::cerr << "Command: Did not receive any bytes!";
		this->command_action = Data::CommandAction::idle;
		break;
	case 1:
		{
			auto command = Serialization.front();
			this->command_action = Data::CommandAction(command);
			break;
		}
	default:
		std::cerr << "Command: Received more than 1 byte!";
		this->command_action = Data::CommandAction::idle;
		break;
	}
}

Data::Command::Command(CommandAction action)
{
	this->command_action = action;
}

Data::IContainer Data::Command::Serialize() const
{
	Data::IContainer result(1, (uint8_t) this->command_action);
	return result;
}

Data::CommandAction Data::Command::getAction() const
{
	return this->command_action;
}

std::unique_ptr<Data::Command> Data::Command::New(Data::IContainer Serialization)
{
	return std::make_unique<Command>(Command(Serialization));
}