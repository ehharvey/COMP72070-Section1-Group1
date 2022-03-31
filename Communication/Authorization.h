#pragma once
#include <memory>
#include <deque>
#include "IAuthorization.h"
#include "IContainer.h"

namespace Data
{
    class Authorization : public IAuthorization
	{
	private:
		uint8_t payload;

		Authorization();
		Authorization(Data::IContainer Serialization);
		Authorization(uint8_t AuthByte);
	public:
		uint8_t getAuthByte();
		Data::IContainer Serialize();

		static std::unique_ptr<Authorization> New(const uint8_t byte);
	};
}