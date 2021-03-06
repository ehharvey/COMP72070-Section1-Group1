#pragma once
#include "SerializationGroup.h"
#include <typeinfo>
#include <iostream>

// Helper class ---------------------------------------------------
class __SizeSerializerHelper : public Data::ISerializable
{
private:
	Data::IContainer size_serialization;
public:
	__SizeSerializerHelper(size_t size)
	: size_serialization(Data::IContainer{})
	{
		while (size > 255)
		{
			size_serialization.push_back(255);
			size -= 255;
		}
		size_serialization.push_back(size);
	}

	__SizeSerializerHelper() : size_serialization(Data::IContainer{}) { };

	__SizeSerializerHelper& Deserialize(Data::IContainer& Serialization)
	{
		this->size_serialization.clear();
		while (!Serialization.empty())
		{
			uint8_t current = Serialization.front();
			size_serialization.push_back(current);
			Serialization.pop_front();

			if (current < 255)
			{
				break;
			}
		}
		return *this;
	}

	Data::IContainer Serialize () const
	{
		return size_serialization;
	}

	size_t getSize()
	{
		return (size_serialization.size() == 0)  ?
			0 :
			((size_serialization.size() - 1) * 255) + size_serialization.back();
	}
};
// ------------------------------------------------------------------------------------------
std::unique_ptr<Data::ISerializable>
deserializeHelperSingle
(Data::IContainer& Serialization, std::shared_ptr<Data::ITypeConstructor> type_constructor)
{
	// TODO: Error handling
	
	// Get type
	uint8_t type_identifier = Serialization.front();
	Serialization.pop_front();

	// Get size
	auto size = __SizeSerializerHelper().Deserialize(Serialization).getSize(); // Modifies Serialization

	// Get object
	auto constructor = type_constructor->getConstructor(type_identifier);

	auto end = Serialization.begin();
	std::advance(end, size);
	Data::IContainer object_serialization;
	object_serialization.splice(object_serialization.begin(), Serialization, Serialization.begin(), end); 

	std::unique_ptr<Data::ISerializable> object = constructor(object_serialization);

	return std::move(object);
}

std::vector<std::unique_ptr<Data::ISerializable>> 
deserializeHelperMultiple
(Data::IContainer Serialization, std::shared_ptr<Data::ITypeConstructor> type_constructor)
{
	std::vector<std::unique_ptr<Data::ISerializable>> result;

	while (Serialization.size() > 0)
	{
		result.push_back(deserializeHelperSingle(Serialization, type_constructor));
	}

	return result;
}

std::unique_ptr < Data::SerializationGroup >
Data::SerializationGroup::New
(std::shared_ptr<ITypeConstructor> type_constructor)
{
	return std::make_unique<SerializationGroup>(SerializationGroup(type_constructor));
}

std::unique_ptr < Data::SerializationGroup >
Data::SerializationGroup::New
(Data::IContainer Serialization, std::shared_ptr<ITypeConstructor> type_constructor)
{
	return std::make_unique<SerializationGroup>(SerializationGroup(type_constructor));
}

Data::SerializationGroup::SerializationGroup
(Data::IContainer Serialization, std::shared_ptr<ITypeConstructor> type_constructor)
: type_constructor(type_constructor)
{
	this->items = deserializeHelperMultiple(Serialization, this->type_constructor);
} 

Data::SerializationGroup::SerializationGroup(std::shared_ptr<ITypeConstructor> type_constructor)
: type_constructor(type_constructor)
{ this->items.clear(); }

std::unique_ptr<Data::ISerializable>
Data::SerializationGroup::getNext
()
{
	if (!this->items.empty())
	{
		auto result = std::move(this->items.back());
		this->items.pop_back();

		return std::move(result);
	}
	else
	{
		return nullptr;
	}
}

Data::ISerializationGroup*
Data::SerializationGroup::add
(std::unique_ptr<ISerializable> item)
{
	this->items.push_back(std::move(item));
	return this;
}

Data::ISerializationGroup*
Data::SerializationGroup::add
(const ISerializable& item)
{
	auto serialization = item.Serialize();
	auto type_identifier = this->type_constructor->getTypeIdentifier(std::type_index(typeid(item)));
	auto constructor = this->type_constructor->getConstructor(type_identifier);

	auto copy = constructor(serialization);

	this->items.push_back(std::move(copy));


	return this;
}


Data::IContainer Data::SerializationGroup::Serialize() const
{ 
	Data::IContainer result;
	for (auto const& item : this->items)
	{
		auto item_serialization = item->Serialize();

		// Insert the type
		auto const& item_type = std::type_index(typeid(*item));
		uint8_t type_identifier = this->type_constructor->getTypeIdentifier(item_type);
		result.push_back(type_identifier);

		// Serialize the size
		{
			auto item_size = item_serialization.size();
			auto size_serialization = __SizeSerializerHelper(item_size).Serialize();
			result.insert(result.end(), size_serialization.begin(), size_serialization.end());
		}
		
		// Serialize the object itself
		{
			result.insert(result.end(), item_serialization.begin(), item_serialization.end());
		}
	}

	return result;
}

Data::ISerializationGroup*
Data::SerializationGroup::Deserialize
(Data::IContainer Serialization)
{
	this->items =  deserializeHelperMultiple(Serialization, this->type_constructor);
	return this;
}