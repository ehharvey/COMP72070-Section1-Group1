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
		
		Data::IContainer Serialize () const;
		CommandAction getAction() const;
		
		static std::unique_ptr<Command> New(Data::IContainer Serialization);
	};

	const std::pair<std::type_index, Data::ISerializableConstructor> command_type_pair = 
	std::make_pair<std::type_index, Data::ISerializableConstructor>
	(std::type_index(typeid(Command)), Data::Command::New);
} // namespace Data
