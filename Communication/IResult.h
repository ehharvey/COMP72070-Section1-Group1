#pragma once
#include "ISerializable.h"

namespace Data
{
    __interface IResult : public Data::ISerializable
    {
        bool AuthSuccess() const;
        Data::IContainer Serialize() const;
    };
}