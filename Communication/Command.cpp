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
}

Data::IContainer Data::Command::Serialize()
{
	return Data::IContainer();
}

Data::CommandAction Data::Command::getAction()
{
	return CommandAction();
}

std::unique_ptr<Data::Command> Data::Command::New(Data::IContainer Serialization)
{
	return std::make_unique<Command>();
}