#pragma once
#include "ISerializable.h"
#include "IContainer.h" 
#include <fstream>
#include <memory>
#include <typeindex>

namespace Data
{
    class Music : public ISerializable
    {
    private:
        std::fstream music_f;
        Data::IContainer __serialized;
    public:
        Music();
        Music(Data::IContainer Serialization);

        Data::IContainer Serialize() const;
        static std::unique_ptr<Music> New();

        static std::unique_ptr<Music> Deserialize(Data::IContainer serialization);
    };

    const std::pair<std::type_index, Data::ISerializableConstructor> music_type_constructor =
        std::make_pair<std::type_index, Data::ISerializableConstructor>
        (std::type_index(typeid(Music)), Data::Music::Deserialize);
}