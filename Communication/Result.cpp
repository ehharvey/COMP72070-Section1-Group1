#include "Result.h"
#include <iostream>

Data::Result::Result(bool authsuccess)
{
    this->auth = authsuccess;
}


Data::Result::Result(Data::IContainer Serialization)
{
    switch (Serialization.size())
	{
	case 0:
		std::cerr << "Result: Did not receive any bytes!";
		this->auth = false;
		break;
	case 1:
		this->auth = Serialization.front();
		break;
	default:
		std::cerr << "Result: Received more than 1 byte!";
		this->auth = false;
		break;
	}
}

bool Data::Result::AuthSuccess() const
{
    return this->auth;
}

Data::IContainer
Data::Result::Serialize() const
{
    Data::IContainer result;
    result.push_back(this->auth);

    return result;
}

std::unique_ptr<Data::Result>
Data::Result::New(bool authsuccess)
{
    return std::make_unique<Data::Result>(Result(authsuccess));
}

std::unique_ptr<Data::Result> Data::Result::Deserialize(Data::IContainer Serialization)
{
    return std::make_unique<Result>(Serialization);
}
