#pragma once
#include "IContainer.h"

namespace Data
{
    enum CommandAction : uint8_t
	{
		feed = 0,
		sleep = 1,
		clean = 2,
		idle = 3,
	};
}