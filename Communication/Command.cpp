#pragma once
#include "Command.h"

Data::Command::Command()
{
}

Data::Command::Command(Data::IContainer Serialization)
{
}

Data::Command::Command(CommandAction action)
{
	this->command_action = action;
}

Data::IContainer Data::Command::Serialize() const
{
	return Data::IContainer();
}

Data::CommandAction Data::Command::getAction() const
{
	return CommandAction();
}

std::unique_ptr<Data::Command> Data::Command::New(Data::IContainer Serialization)
{
	return std::make_unique<Command>();
}