#include "Tamagotchi.h"

void Tamagotchi::Tamagotchi::AddCommand(Data::Command)
{
}

void Tamagotchi::Tamagotchi::AddCommand_Immediate(Data::Command)
{
}

Data::Command Tamagotchi::Tamagotchi::GetCurrentCommand()
{
	return Data::Command();
}

std::unique_ptr<Data::IStatus> Tamagotchi::Tamagotchi::getStatus()
{
	return std::unique_ptr<Data::IStatus>();
}

void Tamagotchi::Tamagotchi::adjustStat(Stat, signed int relativeChange)
{
}
