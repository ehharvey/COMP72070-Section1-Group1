#pragma once
#include "IContainer.h"
#include <vector>
#include <iostream>
#include <typeindex>
#include "ISerializable.h"

namespace Data
{ 
    __interface ISerializationGroup : public ISerializable
	{
		ISerializationGroup*
		Deserialize
		(IContainer Serialization);

		ISerializationGroup* add(std::unique_ptr<ISerializable> item);
		ISerializationGroup* add(const ISerializable& item);

		virtual std::unique_ptr<Data::ISerializable> getNext() = 0; // Will return null when empty
	};

	typedef std::function<std::unique_ptr<ISerializationGroup>()> SerializationGroup_Constructor;
}