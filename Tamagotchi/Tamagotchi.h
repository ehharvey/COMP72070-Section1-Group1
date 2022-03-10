#pragma once
#include <cstdint>
#include <queue>

namespace Tamagotchi 
{
	enum Command
	{
		feed,
		sleep,
		clean
	};

	class TamagotchiStatus {
		uint8_t Payload[2];
	public:
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getDirtiness();
	};

	class Tamagotchi
	{
	private:
		std::queue<Command> Commands;
		TamagotchiStatus Status;

	public:
		void AddCommand(Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Command); // ^^
		Command GetCurrentCommand();
		TamagotchiStatus getStatus();
	};
}