#pragma once
#include "IContainer.h"
#include <memory>
#include "ICommandBuilder.h"
#include "CommandAction.h"
#include "ICommand.h"

namespace Data
{
    class CommandBuilder : public ICommandBuilder
    {
        
    public:
        std::unique_ptr<ICommandBuilder> setCommand(CommandAction command_action);
        std::unique_ptr<ICommand> Build();
    };
}