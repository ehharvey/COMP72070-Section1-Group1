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
		help = 4,
		quit = 5,
		send = 6,
	};
}