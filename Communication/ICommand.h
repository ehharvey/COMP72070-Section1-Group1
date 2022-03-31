#pragma once
#include "IContainer.h"
#include "CommandAction.h"
#include "ISerializable.h"

namespace Data
{
    __interface ICommand : public ISerializable
	{
		CommandAction getAction();
	};
}