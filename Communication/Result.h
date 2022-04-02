#pragma once
#include "IResult.h"
#include <memory>
#include <typeindex>

namespace Data
{
    class Result : public IResult
    {
        bool auth;
        
    public:
        Result(bool authsuccess);
        Result(Data::IContainer Serialization);
        bool AuthSuccess() const;
        Data::IContainer Serialize() const;

        static std::unique_ptr<Result> New(bool auth);
        static std::unique_ptr<Result> Deserialize(Data::IContainer Serialization);
    };

    const std::pair<std::type_index, Data::ISerializableConstructor> result_type_constructor =
        std::make_pair<std::type_index, Data::ISerializableConstructor>
        (std::type_index(typeid(Data::Result)), Result::Deserialize);
} // namespace Data
