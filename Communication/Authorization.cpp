#pragma once
#include "Authorization.h"


Data::Authorization::Authorization(std::vector<uint8_t> Serialization)
{
}

Data::Authorization::Authorization(uint8_t AuthByte)
{
}

uint8_t Data::Authorization::getAuthByte()
{
	return uint8_t();
}

const std::vector<uint8_t> Data::Authorization::Serialize()
{
	return std::vector<uint8_t>();
}