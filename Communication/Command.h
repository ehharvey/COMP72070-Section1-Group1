#pragma once
#include <memory>
#include <vector>
#include "CommandAction.h"
#include "ISerializationGroup.h"
#include "ICommand.h"

namespace Data
{
    class Command : public ICommand
	{
	private:
		CommandAction command_action;
	public:
		Command();
		Command(const std::vector<uint8_t> Serialization);
		Command(CommandAction action);

		const std::vector<uint8_t> Serialize();
		CommandAction getAction();
		
		static std::unique_ptr<Command> New(const std::vector<uint8_t> Serialization);
	};
} // namespace Data
