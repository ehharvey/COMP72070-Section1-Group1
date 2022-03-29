#pragma once
#include <vector>

namespace Data
{
    __interface ISerializable
	{
		const std::vector<uint8_t> Serialize();
	};
}