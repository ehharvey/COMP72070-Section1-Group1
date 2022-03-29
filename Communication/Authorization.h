#pragma once
#include <vector>
#include "IAuthorization.h"

namespace Data
{
    class Authorization : public IAuthorization
	{
	public:
		Authorization(std::vector<uint8_t> Serialization);
		Authorization(uint8_t AuthByte);
		uint8_t getAuthByte();
		const std::vector<uint8_t> Serialize();
	};
}