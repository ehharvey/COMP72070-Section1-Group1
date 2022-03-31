#pragma once
#include "IContainer.h"
#include <deque>
#include <typeindex>
#include <memory>
#include <utility>
#include <unordered_map>
#include "ISerializable.h"
#include "ISerializationGroup.h"
#include "ITypeConstructor.h"


namespace Data
{
    class SerializationGroup : public ISerializationGroup
    {
    private:
        // Serialization information:
        // uint_16 indicating size of subsequent transmission (not part of this)
        // [ type uint8_t: serialization ]  <--- Item #1
        // [ type uint8_t: serialization ]  <--- Item #2

        std::shared_ptr<ITypeConstructor> type_constructor;

        std::vector<std::unique_ptr<ISerializable>> items;

        SerializationGroup(Data::IContainer Serialization, std::shared_ptr<ITypeConstructor> type_constructor);
        SerializationGroup(std::shared_ptr<ITypeConstructor> type_constructor);
    public:
        std::vector<std::unique_ptr<ISerializable>>::iterator begin();
        std::vector<std::unique_ptr<ISerializable>>::iterator end();

        Data::ISerializationGroup&
        Deserialize
        (IContainer Serialization);

        // Returns a map *items*
        // items[typeid(ClientRequest)] retrieves all ClientRequest objects contained
        
        ISerializationGroup* add(std::unique_ptr<ISerializable> item); 
        ISerializationGroup* add(std::shared_ptr<ISerializable> item);

        Data::IContainer Serialize();

        static std::unique_ptr<SerializationGroup> New();
        

        static std::unique_ptr<SerializationGroup> 
        New
        (std::shared_ptr<ITypeConstructor> type_constructor);

        static std::unique_ptr<SerializationGroup> 
        New
        (Data::IContainer Serialization, std::shared_ptr<ITypeConstructor> type_constructor);
    };
} // namespace Data


