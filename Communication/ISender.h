#pragma once
#include <vector>

namespace Communicators
{
    __interface ISender
	{
		const std::vector<uint8_t> Send(const std::vector<uint8_t> message); // Returns the received response
	};
} // namespace Communicators
