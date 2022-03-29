#pragma once
#include "IContainer.h"
#include <vector>
#include <typeindex>
#include <memory>
#include <unordered_map>
#include "ISerializable.h"
#include "ISerializationGroup.h"
#include "_packet.h"


namespace Data
{
    class SerializationGroup : public ISerializationGroup
    {
    private:
        std::vector<_packet> items;
    public:
        SerializationGroup(Data::IContainer Serialization);
        SerializationGroup();

        std::vector<_packet>::iterator begin();
        std::vector<_packet>::iterator end();

        // Returns a map *items*
        // items[typeid(ClientRequest)] retrieves all ClientRequest objects contained
        std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>> get();
        
        std::unique_ptr<ISerializationGroup> add(std::unique_ptr<ISerializable> item);
        std::unique_ptr<ISerializationGroup> add(std::shared_ptr<ISerializable> item);
        Data::IContainer Serialize();

        static std::unique_ptr<SerializationGroup> New();
    };
} // namespace Data


