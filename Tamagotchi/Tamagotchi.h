#pragma once
#include <cstdint>
#include <utility>
#include <deque>
#include <chrono>
#include <optional>
#include "../Communication/Create.h"

namespace Tamagotchi 
{
	// Interfaces ------------------------------------------------------------------
		__interface ITamagotchi : public Data::ISerializable
	{
		void AddCommand(Data::CommandAction); // This also needs durations? (We can also scrap durations)
		std::unique_ptr<Data::ICommand> GetCurrentCommand();
		std::unique_ptr<Data::IStatus> getStatusCopy();
		Data::IAuthorization& getAuthorization();

	};
	// -----------------------------------------------------------------------------

	class Tamagotchi : public ITamagotchi
	{
	private:
		std::deque<Data::CommandAction> Commands;
		std::shared_ptr<Data::IAuthorization> Authorization;
		std::unique_ptr<Data::IStatus> Stats;
		void RecalculateHappiness();
		void ProcessCommands();
		std::chrono::time_point<std::chrono::steady_clock> last_command_time;
		uint8_t getStat(Data::Stat stat);
	public:
		void AddCommand(Data::CommandAction);
		std::unique_ptr<Data::ICommand> GetCurrentCommand();
		Data::IAuthorization& getAuthorization();
		std::unique_ptr<Data::IStatus> getStatusCopy();
		Tamagotchi(std::unique_ptr<Data::IStatus> status, std::unique_ptr<Data::IAuthorization> authorization);

		Data::IContainer Serialize() const;
		static std::optional<std::unique_ptr<Tamagotchi>> Deserialize(Data::IContainer serialization);
	};
}