#pragma once
#include "IResult.h"

namespace Data
{
    class Result : public IResult
    {
        bool auth;
        Result(bool authsuccess);
        Result(Data::IContainer Serialization);
    public:
        bool AuthSuccess();
        Data::IContainer Serialize();
    };
} // namespace Data
