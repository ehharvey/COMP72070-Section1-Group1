#pragma once
#include "ISerializable.h"
#include <typeindex>
#include <utility>

namespace Data
{
    class ErrorSerialization : public ISerializable
    {
    public:
        ErrorSerialization();
        Data::IContainer Serialize() const;
        static std::unique_ptr<ErrorSerialization> New(Data::IContainer Serialization);
    };

    const std::pair<std::type_index, Data::ISerializableConstructor> error_type_constructor =
	std::make_pair<std::type_index, Data::ISerializableConstructor>
	(std::type_index(typeid(Data::ErrorSerialization)), Data::ErrorSerialization::New);
}