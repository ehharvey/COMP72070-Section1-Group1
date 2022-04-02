#pragma once
#include "IAuthorization.h"
#include "IContainer.h"
#include "ISerializable.h"
#include "ICommand.h"
#include <memory>

namespace Data
{
    __interface IClientRequest : public ISerializable
	{
		ICommand & getCommand() const;
		IAuthorization & getAuthorization() const;
	};
} // namespace Data
