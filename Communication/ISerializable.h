#pragma once
#include "IContainer.h"
#include <vector>

namespace Data
{
    __interface ISerializable
	{
		Data::IContainer Serialize();
	};
}