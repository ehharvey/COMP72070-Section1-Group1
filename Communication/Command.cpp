#pragma once
#include "Command.h"

Data::Command::Command()
{
}

Data::Command::Command(const std::vector<uint8_t> Serialization)
{
}

Data::Command::Command(CommandAction action)
{
}

const std::vector<uint8_t> Data::Command::Serialize()
{
	return std::vector<uint8_t>();
}

Data::CommandAction Data::Command::getAction()
{
	return CommandAction();
}

std::unique_ptr<Data::Command> Data::Command::New(const std::vector<uint8_t> Serialization)
{
	return std::make_unique<Command>();
}