#pragma once
#include <typeindex>
#include <map>
#include "IContainer.h"
#include "ISerializable.h"

namespace Data
{
    __interface ITypeConstructor
    {
        uint8_t getTypeIdentifier(const std::type_info&) const; // For Serialization: get byte
        ISerializableConstructor getConstructor(uint8_t type_identifier) const; // For Deserialization: get constructor

        void __setConstructor(ISerializableConstructor);
    };
} // namespace Data
