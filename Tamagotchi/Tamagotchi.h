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
	__interface IStatus
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
		Status getStatus();
	};

	class Status : public IStatus {
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
		Status _Status;

	public:
		void AddCommand(Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Command); // ^^
		Command GetCurrentCommand();
		Status getStatus();
	};
}

namespace TamagotchiMocks {
	class MockTamagotchi : public Tamagotchi::ITamagotchi {
		MOCK_METHOD(void, AddCommand, (Tamagotchi::Command));
		MOCK_METHOD(void, AddCommand_Immediate, (Tamagotchi::Command));
		MOCK_METHOD(Tamagotchi::Command, GetCurrentCommand, ());
		MOCK_METHOD(Tamagotchi::Status, getStatus, ());
	};

	class MockStatus : public Tamagotchi::Status {
		MOCK_METHOD(uint8_t, getHappiness, ());
		MOCK_METHOD(uint8_t, getAlertness, ());
		MOCK_METHOD(uint8_t, getStomachLevel, ());
		MOCK_METHOD(uint8_t, getDirtiness, ());
	};
}