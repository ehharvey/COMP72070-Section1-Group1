#pragma once
#include <iostream>
#include <deque>
#include "Authorization.h"


Data::Authorization::Authorization(Data::IContainer Serialization)
: payload(Serialization[0])
{
	if (Serialization.size() > 1)
	{
		std::cerr << "Authorization: Received more than 1 byte!";
	}

	Serialization.
}

Data::Authorization::Authorization(uint8_t AuthByte)
{
}

uint8_t Data::Authorization::getAuthByte()
{
	return uint8_t();
}

Data::IContainer Data::Authorization::Serialize()
{
	return Data::IContainer();
}