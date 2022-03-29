#pragma once
#include "SerializationGroup.h"

std::unique_ptr < Data::SerializationGroup > Data::SerializationGroup::New()
{
	return std::unique_ptr<SerializationGroup>();
}

Data::SerializationGroup::SerializationGroup(Data::IContainer Serialization)
{
}

Data::SerializationGroup::SerializationGroup()
{
}

std::vector<Data::_packet>::iterator Data::SerializationGroup::begin()
{
	return std::vector<_packet>::iterator();
}

std::vector<Data::_packet>::iterator Data::SerializationGroup::end()
{
	return std::vector<_packet>::iterator();
}

std::unordered_map<std::type_index, std::vector<std::unique_ptr<Data::ISerializable>>> Data::SerializationGroup::get()
{
	return std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>>();
}

std::unique_ptr<Data::ISerializationGroup> Data::SerializationGroup::add(std::unique_ptr<ISerializable> item)
{
	return std::unique_ptr<ISerializationGroup>();
}

std::unique_ptr<Data::ISerializationGroup> Data::SerializationGroup::add(std::shared_ptr<ISerializable> item)
{
	return std::unique_ptr<ISerializationGroup>();
}

Data::IContainer Data::SerializationGroup::Serialize()
{
	return Data::IContainer();
}
