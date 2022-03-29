#pragma once
#include "ISerializable.h"
#include "ICommand.h"
#include <memory>

namespace Data
{
    __interface IClientRequest : public ISerializable
	{
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();
	};
} // namespace Data
