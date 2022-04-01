#include "Tamagotchi.h"
Tamagotchi::Tamagotchi::Tamagotchi() {

}
Tamagotchi::Tamagotchi::Tamagotchi(Data::Status s) {
	Stats = std::make_unique<Data::Status>(s);
}

void Tamagotchi::Tamagotchi::RecalculateHappiness()
{
	Stats->setHappiness(uint8_t(Stats->getAlertness() + Stats->getCleaniness() + Stats->getStomachLevel() / 3));
}

void Tamagotchi::Tamagotchi::AddCommand(Data::CommandAction c)
{
	Commands.emplace_back(c);
}

void Tamagotchi::Tamagotchi::AddCommand_Immediate(Data::CommandAction c)
{
	Commands.emplace_front(c);
}

Data::CommandAction Tamagotchi::Tamagotchi::GetCurrentCommand()
{
	return Commands.front();
}

//std::unique_ptr<Data::IStatus> Tamagotchi::Tamagotchi::getStatus()
//{
	//return std::unique_ptr<Data::IStatus>(Stats);
//}
uint8_t Tamagotchi::Tamagotchi::getStat(Data::Stat stat) {
	uint8_t value;
	switch (stat) {
	case 1:
		value = Stats->getAlertness();
		break;
	case 2:
		value = Stats->getStomachLevel();
		break;
	case 3:
		value = Stats->getCleaniness();
		break;
	case 4:
		value = Stats->getHappiness();
		break;
	}
	return value;
}
void Tamagotchi::Tamagotchi::adjustStat(Data::Stat stat, signed int relativeChange)
{
	switch (stat) {
	case 1:
		Stats->setAlertness(Stats->getAlertness() + relativeChange);
		break;
	case 2:
		Stats->setStomachLevel(Stats->getStomachLevel() + relativeChange);
		break;
	case 3:
		Stats->setCleaniness(Stats->getCleaniness() + relativeChange);
		break;
	case 4:
		Stats->setHappiness(Stats->getHappiness() + relativeChange);
		break;
	}
}
