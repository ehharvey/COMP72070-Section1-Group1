#include "Tamagotchi.h"

void
Tamagotchi::Tamagotchi::ProcessCommands()
{
	auto diff_time = std::chrono::steady_clock::now() - this->last_command_time;
	auto seconds_since = std::chrono::duration_cast<std::chrono::seconds>(diff_time);
	auto num_of_cycles = seconds_since.count() / 30;

	for (auto i = 0; i < num_of_cycles; i++)
	{
		if (this->Commands.size() > 0)
		{
			auto command = this->Commands.front();
			this->Commands.pop_front();

			switch (command)
			{
			case Data::CommandAction::clean:
				{
					auto current_clean = this->Stats->getCleaniness();
					current_clean += 5;
					this->Stats->setCleaniness(current_clean);
				}
				break;
			case Data::CommandAction::feed:
				{
					auto current_stomach = this->Stats->getStomachLevel();
					current_stomach += 5;
					this->Stats->setStomachLevel(current_stomach);
				}
				break;
			case Data::CommandAction::sleep:
				{
					auto current_alert = this->Stats->getAlertness();
					current_alert += 5;
					this->Stats->setAlertness(current_alert);
				}
				break;
			}			
		}

		// Decrement all stats by 1
		auto current_clean = this->Stats->getCleaniness();
		current_clean--;
		this->Stats->setCleaniness(current_clean);
		auto current_stomach = this->Stats->getStomachLevel();
		current_stomach--;
		this->Stats->setCleaniness(current_stomach);
		auto current_alert = this->Stats->getAlertness();
		current_alert--;
		this->Stats->setAlertness(current_alert);

		this->RecalculateHappiness();
	}
	this->last_command_time = std::chrono::steady_clock::now();
}


Tamagotchi::Tamagotchi::Tamagotchi(std::unique_ptr<Data::IStatus> status) {
	Stats = std::move(status);
	this->last_command_time = std::chrono::steady_clock::now();
}

void Tamagotchi::Tamagotchi::RecalculateHappiness()
{
	Stats->setHappiness(uint8_t(Stats->getAlertness() + Stats->getCleaniness() + Stats->getStomachLevel() / 3));
}

void Tamagotchi::Tamagotchi::AddCommand(Data::CommandAction c)
{
	Commands.push_back(c);
}

void Tamagotchi::Tamagotchi::AddCommand_Immediate(Data::CommandAction c)
{
	Commands.push_front(c);
}

Data::CommandAction Tamagotchi::Tamagotchi::GetCurrentCommand()
{
	switch (Commands.size())
	{
	case 0:
		return Data::CommandAction::idle;
		break;
	default:
		return Commands.front();
	}
}

//std::unique_ptr<Data::IStatus> Tamagotchi::Tamagotchi::getStatus()
//{
	//return std::unique_ptr<Data::IStatus>(Stats);
//}
uint8_t Tamagotchi::Tamagotchi::getStat(Data::Stat stat) {
	this->ProcessCommands();
	uint8_t value;
	switch (stat) 
	{
	case Data::Stat::alertness: 
		value = Stats->getAlertness();
		break;
	case Data::Stat::stomachlevel:
		value = Stats->getStomachLevel();
		break;
	case Data::Stat::cleanliness: 
		value = Stats->getCleaniness();
		break;
	case Data::Stat::happiness: 
		value = Stats->getHappiness();
		break;
	}

	return value;
}