#pragma once
#include <vector>
#include <functional>

namespace Communicators
{
    // rPtr: a lambda function indicating the response to an input
	// - Needs to be a function that receives a std::vector<uint8_t>	<---- (the request)
	// - This function needs to also return a std::vector<uint8_t>		<---- (the response)
	typedef std::function<std::vector<uint8_t>(std::vector<uint8_t>)> rPtr;
} // namespace Communicators
