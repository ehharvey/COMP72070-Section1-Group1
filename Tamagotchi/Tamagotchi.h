#pragma once
#include <cstdint>
#include <deque>
#include "gmock/gmock.h"

namespace Tamagotchi 
{
	enum Command
	{
		feed,
		sleep,
		clean,
		idle
	};

	enum Stat {
		alertness, stomach, cleanliness, happiness
	};

	// Interfaces :
	__interface IStatus
	{
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getCleaniness();
		void setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
	};

	__interface ITamagotchi
	{
		void AddCommand(Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Command); // ^^
		Command GetCurrentCommand();
		IStatus& getStatus();
		void adjustStat(enum Stat, signed int relativeChange);
	};

	class Status : public IStatus {
		// Payload format
		// hhhh aaaa [happiness alertness]
		// ssss cccc [stomach cleaniness]
		uint16_t Payload; // 2 bytes
	public:
		uint8_t getHappiness() { return Payload >> 12; };
		uint8_t getAlertness() { return Payload << 4 >> 12; };
		uint8_t getStomachLevel() { return Payload << 8 >> 12; };
		uint8_t getCleaniness() { return Payload << 12 >> 12; };

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);
		void setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
	};

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Command> Commands;
		IStatus& Stats;

		void RecalculateHappiness() { 
			uint16_t alertness = Stats.getAlertness();
			uint16_t stomach = Stats.getStomachLevel();
			uint16_t cleaniness = Stats.getCleaniness();
			uint8_t new_happiness = (uint8_t) ((alertness + stomach + cleaniness) / 3); 

			Stats.setStats(happiness, alertness, cleaniness, stomach);
		}

	public:
		void AddCommand(Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Command); // ^^
		Command GetCurrentCommand();
		IStatus& getStatus();
		void adjustStat(enum Stat, signed int relativeChange);
	};
}

namespace TamagotchiMocks {
	class MockTamagotchi : public Tamagotchi::ITamagotchi {
		MOCK_METHOD(void, AddCommand, (Tamagotchi::Command));
		MOCK_METHOD(void, AddCommand_Immediate, (Tamagotchi::Command));
		MOCK_METHOD(Tamagotchi::Command, GetCurrentCommand, ());
		MOCK_METHOD(Tamagotchi::IStatus&, getStatus, ());
	};

	class MockStatus : public Tamagotchi::Status {
		MOCK_METHOD(uint8_t, getHappiness, ());
		MOCK_METHOD(uint8_t, getAlertness, ());
		MOCK_METHOD(uint8_t, getStomachLevel, ());
		MOCK_METHOD(uint8_t, getDirtiness, ());
	};
}