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
		void adjustStat(Data::Stat, signed int relativeChange);
	};
	// -----------------------------------------------------------------------------

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Data::Command> Commands;
		std::unique_ptr<Data::IStatus> Stats;

		void RecalculateHappiness();

	public:
		void AddCommand(Data::Command); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::Command); // ^^
		Data::Command GetCurrentCommand();
		std::unique_ptr<Data::IStatus> getStatus();
		void adjustStat(Data::Stat, signed int relativeChange);
	};
}

namespace Mocks {
	class TamagotchiMock : public Tamagotchi::ITamagotchi {
	public:
		MOCK_METHOD(void, AddCommand, (Data::Command));
		MOCK_METHOD(void, AddCommand_Immediate, (Data::Command));
		MOCK_METHOD(Data::Command, GetCurrentCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getStatus, ());
		MOCK_METHOD(void, adjustStat, (Data::Stat, signed int relativeChange));
	};
}