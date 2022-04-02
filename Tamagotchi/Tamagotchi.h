#pragma once
#include <cstdint>
#include <deque>
#include "../Communication/Create.h"

namespace Tamagotchi 
{
	// Interfaces ------------------------------------------------------------------
		__interface ITamagotchi
	{
		void AddCommand(Data::CommandAction); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::CommandAction); // ^^
		Data:: CommandAction GetCurrentCommand();
		//std::unique_ptr<Data::IStatus> getStatus();
		void adjustStat(Data::Stat, signed int relativeChange);
	};
	// -----------------------------------------------------------------------------

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Data::CommandAction> Commands;
		std::unique_ptr<Data::IStatus> Stats;

		void RecalculateHappiness();

	public:
	
		void AddCommand(Data::CommandAction); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::CommandAction); // ^^
		Data::CommandAction GetCurrentCommand();
		uint8_t getStat(Data::Stat);
		void adjustStat(Data::Stat, signed int relativeChange);
		Tamagotchi();
		Tamagotchi(Data::Status s);
	};
}