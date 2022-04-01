#pragma once
#include "IContainer.h"
#include <vector>
#include <typeindex>
#include "ISerializable.h"

namespace Data
{ 
    __interface ISerializationGroup : public ISerializable
	{
		std::vector<std::unique_ptr<ISerializable>>::iterator begin();
        std::vector<std::unique_ptr<ISerializable>>::iterator end();

		ISerializationGroup&
		Deserialize
		(IContainer Serialization);

		ISerializationGroup& add(std::unique_ptr<ISerializable> item);
		ISerializationGroup& add(const ISerializable& item);
	};

	typedef std::function<std::unique_ptr<ISerializationGroup>()> SerializationGroup_Constructor;
}