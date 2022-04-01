#pragma once
#include <map>
#include "Command.h"

Data::Command::Command()
: command_action(idle)
{
}

Data::Command::Command(Data::IContainer Serialization)
{
	auto command = Serialization.front();

	this->command_action = Data::CommandAction(command);

	Serialization.pop_front();
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