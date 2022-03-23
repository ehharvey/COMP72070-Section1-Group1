#pragma once
#include <cstdint>
#include <deque>
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Tamagotchi 
{
	// Interfaces ------------------------------------------------------------------
		__interface ITamagotchi
	{
		void AddCommand(Data::Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::Command); // ^^
		Data:: Command GetCurrentCommand();
		std::unique_ptr<Data::IStatus> getStatus();
		void adjustStat(enum Stat, signed int relativeChange);
	};
	// -----------------------------------------------------------------------------

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Data::Command> Commands;
		std::unique_ptr<Data::IStatus> Stats;

		void RecalculateHappiness() { 
			uint16_t alertness = Stats->getAlertness();
			uint16_t stomach = Stats->getStomachLevel();
			uint16_t cleaniness = Stats->getCleaniness();
			uint8_t new_happiness = (uint8_t) ((alertness + stomach + cleaniness) / 3); 

			Stats->setStats(new_happiness, alertness, cleaniness, stomach);
		}

	public:
		void AddCommand(Data::Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::Command); // ^^
		Data::Command GetCurrentCommand();
		std::unique_ptr<Data::IStatus> getStatus();
		void adjustStat(enum Stat, signed int relativeChange);
	};
}

namespace TamagotchiMocks {
	class MockTamagotchi : public Tamagotchi::ITamagotchi {
		MOCK_METHOD(void, AddCommand, (Data::Command));
		MOCK_METHOD(void, AddCommand_Immediate, (Data::Command));
		MOCK_METHOD(Data::Command, GetCurrentCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getStatus, ());
	};
}