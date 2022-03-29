#pragma once
#include "IContainer.h"
#include <vector>
#include <typeindex>
#include <unordered_map>
#include "_packet.h"
#include "ISerializable.h"

namespace Data
{ 
    __interface ISerializationGroup : public ISerializable
	{
		std::vector<_packet>::iterator begin();
		std::vector<_packet>::iterator end();

		// Returns a map *items*
		// items[typeid(ClientRequest)] retrieves all ClientRequest objects contained
		std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>> get();

		std::unique_ptr<ISerializationGroup> add(std::unique_ptr<ISerializable> item);
		std::unique_ptr<ISerializationGroup> add(std::shared_ptr<ISerializable> item);
	};
}