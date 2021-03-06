#pragma once
#include <iostream>
#include <deque>
#include "Authorization.h"


Data::Authorization::Authorization(Data::IContainer Serialization)
{
	switch (Serialization.size())
	{
	case 0:
		std::cerr << "Authorization: Did not receive any bytes!";
		this->payload = 0;
		break;
	case 1:
		this->payload =Serialization.front();
		break;
	default:
		std::cerr << "Authorization: Received more than 1 byte!";
		this->payload = 0;
		break;
	}
}

Data::Authorization::Authorization(uint8_t AuthByte)
: payload(AuthByte)
{ }

uint8_t Data::Authorization::getAuthByte() const
{
	return this->payload;
}

Data::IContainer Data::Authorization::Serialize() const
{
	return Data::IContainer(1, payload);
}

std::unique_ptr<Data::Authorization> Data::Authorization::New(const uint8_t byte)
{
	return std::make_unique<Data::Authorization>(Data::Authorization(byte));
}

std::unique_ptr<Data::Authorization> Data::Authorization::Deserialize(Data::IContainer Serialization)
{
	return std::make_unique<Data::Authorization>(Data::Authorization(Serialization));
}