#pragma once
#include <memory>
#include <vector>
#include "ITypeConstructor.h"

namespace Data
{
    class TypeConstructor : public ITypeConstructor
    {
    private:
        static std::shared_ptr<TypeConstructor> __singleton;
        std::map<std::type_index, uint8_t> type_identifier_map;
        std::vector<ISerializableConstructor> constructors; // Index corresponds to type_identifier

        TypeConstructor(std::vector<ISerializableConstructor> constructors);
    public:
        ISerializableConstructor getConstructor(uint8_t type_identifier) const; // For Deserialization: get constructor
        uint8_t getTypeIdentifier(const std::type_info&) const; // For Serialization: get byte identifier

        void __setConstructor(ISerializableConstructor);

        static std::shared_ptr<TypeConstructor> New(std::vector<ISerializableConstructor> constructors);
    };
} // namespace Data
