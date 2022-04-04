#include "Music.h"

Data::Music::Music()
{
    this->music_f.open("music.mp3", std::ios::binary);

    std::copy(std::istream_iterator<uint8_t>(music_f), std::istream_iterator<uint8_t>(), std::back_inserter(__serialized));
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