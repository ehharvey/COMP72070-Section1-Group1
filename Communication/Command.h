#pragma once
#include "IContainer.h"
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
		Command(Data::IContainer Serialization);
		Command(CommandAction action);

		Data::IContainer Serialize();
		CommandAction getAction();
		
		static std::unique_ptr<Command> New(Data::IContainer Serialization);
	};
} // namespace Data
