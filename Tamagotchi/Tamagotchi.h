#pragma once
#include <cstdint>
#include <queue>
#include "gmock/gmock.h"

namespace Tamagotchi 
{
	enum Command
	{
		feed,
		sleep,
		clean
	};

	// Interfaces :
	__interface ITamagotchiStatus
	{
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getDirtiness();
	};

	__interface ITamagotchi
	{
		void AddCommand(Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Command); // ^^
		Command GetCurrentCommand();
		TamagotchiStatus getStatus();
	};

	class TamagotchiStatus : public ITamagotchiStatus {
		uint8_t Payload[2];
	public:
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getDirtiness();
	};

	class Tamagotchi : public ITamagotchi
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

namespace TamagotchiMocks {
	class MockTamagotchi : public Tamagotchi::ITamagotchi {
	};
}