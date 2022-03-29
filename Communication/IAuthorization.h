#pragma once
#include "ISerializable.h"

namespace Data
{
    __interface IAuthorization : public ISerializable
	{
		uint8_t getAuthByte();
	};
} // namespace Data
