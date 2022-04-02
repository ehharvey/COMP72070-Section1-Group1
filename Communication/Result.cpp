#include "Result.h"
#include <iostream>

Data::Result::Result(bool authsuccess)
{
    this->auth = authsuccess;
}

Data::Result::Result(Data::IContainer Serialization)
{
    this->auth = Serialization.front();
    Serialization.pop_front();
    if (Serialization.size() > 0)
    {
        std::cerr << "Result: Deserializer received more than 1 byte!\n";
    }
}

bool Data::Result::AuthSuccess()
{
    return this->auth;
}

Data::IContainer
Data::Result::Serialize()
{
    Data::IContainer result;
    result.push_back(this->auth);

    return result;
}