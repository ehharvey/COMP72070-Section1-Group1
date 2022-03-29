#include "Tamagotchi.h"

void Tamagotchi::Tamagotchi::RecalculateHappiness()
{
}

void Tamagotchi::Tamagotchi::AddCommand(Data::CommandAction)
{
}

void Tamagotchi::Tamagotchi::AddCommand_Immediate(Data::CommandAction)
{
}

Data::CommandAction Tamagotchi::Tamagotchi::GetCurrentCommand()
{
	return Data::CommandAction();
}

std::unique_ptr<Data::IStatus> Tamagotchi::Tamagotchi::getStatus()
{
	return std::unique_ptr<Data::IStatus>();
}

void Tamagotchi::Tamagotchi::adjustStat(Data::Stat stat, signed int relativeChange)
{
}
