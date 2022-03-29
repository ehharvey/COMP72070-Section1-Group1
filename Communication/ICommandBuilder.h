#pragma once
#include "IContainer.h"
#include <memory>
#include "ICommand.h"

namespace Data
{
    __interface ICommandBuilder
    {
        std::unique_ptr<ICommandBuilder> setCommand(CommandAction command_action);
        std::unique_ptr<ICommand> Build();
    };
} // namespace Data
