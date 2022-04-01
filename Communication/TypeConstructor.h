#pragma once
#include <memory>
#include <vector>
#include <typeindex>
#include "ITypeConstructor.h"

namespace Data
{
    class TypeConstructor : public ITypeConstructor
    {
    private:
        std::unordered_map<std::type_index, uint8_t> type_identifier_map;
        std::vector<ISerializableConstructor> constructors; // Index corresponds to type_identifier

    public:
        TypeConstructor
        (std::vector<std::pair<std::type_index, ISerializableConstructor>> types_and_constructors);

        ISerializableConstructor getConstructor(uint8_t type_identifier) const; // For Deserialization: get constructor
        uint8_t getTypeIdentifier(std::type_index ti) const; // For Serialization: get byte identifier

        void __setConstructor(ISerializableConstructor);

        static std::shared_ptr<TypeConstructor> 
        New
        (std::vector<std::pair<std::type_index, ISerializableConstructor>> types_and_constructors);
    };
} // namespace Data
