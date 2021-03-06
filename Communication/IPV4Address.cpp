#pragma once
#include "IPV4Address.h"

std::string Data::IPV4Address::ToString()
{
    std::string result;
    for (auto const& o : this->octet)
    {
        result.append(std::to_string((int) o));
        result.append(".");
    }
    result.pop_back();
    return result;
}