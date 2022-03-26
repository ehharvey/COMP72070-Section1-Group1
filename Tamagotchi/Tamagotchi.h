#pragma once
#include <cstdint>
#include <deque>
#include "../Communication/Create.h"

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