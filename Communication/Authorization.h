#pragma once
#include <memory>
#include <deque>
#include <typeindex>
#include "IAuthorization.h"
#include "IContainer.h"

namespace Data
{
    class Authorization : public IAuthorization
	{
	private:
		uint8_t payload;

		Authorization();
		Authorization(Data::IContainer Serialization);
		Authorization(uint8_t AuthByte);
	public:
		uint8_t getAuthByte() const;
		Data::IContainer Serialize () const;

		static std::unique_ptr<Authorization> New(const uint8_t byte);

		static std::unique_ptr<Authorization> Deserialize(Data::IContainer Serialization);
	};
	
	const std::pair<std::type_index, Data::ISerializableConstructor> authorization_type_constructor = 
	std::make_pair<std::type_index, Data::ISerializableConstructor>
	(std::type_index(typeid(Authorization)), Data::Authorization::Deserialize);
}