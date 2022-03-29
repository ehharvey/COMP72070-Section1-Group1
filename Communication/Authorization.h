#pragma once
#include <deque>
#include "IAuthorization.h"
#include "IContainer.h"

namespace Data
{
    class Authorization : public IAuthorization
	{
	private:
		uint8_t payload;
	public:
		Authorization(Data::IContainer Serialization);
		Authorization(uint8_t AuthByte);
		uint8_t getAuthByte();
		Data::IContainer Serialize();
	};
}