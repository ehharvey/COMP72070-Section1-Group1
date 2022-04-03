#include "Music.h"

Data::Music::Music()
{
    this->music_f.open("music.mp3", std::ios::binary);

    while (!music_f.eof())
    {
        __serialized.push_back(music_f.get());
    }
}

Data::Music::Music(Data::IContainer Serialization)
{
    this->__serialized = Serialization;
}

Data::IContainer
Data::Music::Serialize() const
{
    return __serialized;
}

std::unique_ptr<Data::Music> Data::Music::New()
{
    return std::make_unique<Music>(Music());
}

std::unique_ptr<Data::Music> Data::Music::Deserialize(Data::IContainer serialization)
{
    return std::make_unique<Music>(Music(serialization));
}