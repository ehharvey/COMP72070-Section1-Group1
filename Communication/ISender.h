#pragma once
#include "IContainer.h"
#include <vector>

namespace Communicators
{
    __interface ISender
	{
		Data::IContainer Send(Data::IContainer message); // Returns the received response
	};
} // namespace Communicators
