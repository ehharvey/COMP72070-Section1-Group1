#pragma once
#include <cstdint>
#include <utility>
#include <deque>
#include <chrono>
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
		uint8_t getStat(Data::Stat);
	};
	// -----------------------------------------------------------------------------

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Data::CommandAction> Commands;

		std::unique_ptr<Data::IStatus> Stats;
		void RecalculateHappiness();
		void ProcessCommands();
		std::chrono::time_point<std::chrono::steady_clock> last_command_time;
	public:
		void AddCommand(Data::CommandAction); // This also needs durations? (We can also scrap durations)
		void AddCommand_Immediate(Data::CommandAction); // ^^
		Data::CommandAction GetCurrentCommand();
		uint8_t getStat(Data::Stat);
		Tamagotchi(std::unique_ptr<Data::IStatus> status);
	};
}