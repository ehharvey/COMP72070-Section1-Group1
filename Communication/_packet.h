#pragma once
#include <memory>
#include <typeinfo>
#include "ISerializable.h"

namespace Data
{
    struct _packet
    {
        struct header
        {
            std::type_info type;
        };
        std::unique_ptr<ISerializable> item;
    };
}

