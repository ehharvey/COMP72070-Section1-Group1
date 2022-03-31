#pragma once
#include <iostream>
#include <deque>
#include "Authorization.h"


Data::Authorization::Authorization(Data::IContainer Serialization)
: payload(Serialization.front())
{
	if (Serialization.size() > 1)
	{
		std::cerr << "Authorization: Received more than 1 byte!";
	}
	
	Serialization.pop_front();
}

Data::Authorization::Authorization(uint8_t AuthByte)
: payload(AuthByte)
{
}

uint8_t Data::Authorization::getAuthByte()
{
	return this->payload;
}

Data::IContainer Data::Authorization::Serialize()
{
	return Data::IContainer(1, payload);
}

std::unique_ptr<Data::Authorization> Data::Authorization::New(const uint8_t byte)
{
	return std::make_unique<Data::Authorization>(Data::Authorization(byte));
}