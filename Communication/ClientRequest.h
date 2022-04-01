#pragma once
#include <memory>
#include <functional>
#include "ISerializationGroup.h"
#include "IContainer.h"
#include "IClientRequest.h"
#include "ICommand.h"
#include "IAuthorization.h"
#include "ISerializable.h"

namespace Data
{
	class ClientRequest : public IClientRequest {
	private:
		Data::SerializationGroup_Constructor serialization_group_constructor;

		std::shared_ptr<IAuthorization> authorization;
		std::shared_ptr<ICommand> command;
		
		ClientRequest(std::shared_ptr<IAuthorization> authorization, 
			std::shared_ptr<Data::ICommand> command,
			SerializationGroup_Constructor serialization_group_constructor);

		ClientRequest(Data::IContainer Serialization, 
			SerializationGroup_Constructor serialization_group_constructor);
	public:
		IAuthorization& getAuthorization() const;
		ICommand& getCommand() const;

		Data::IContainer Serialize () const;

		// Use these "constructors"
		static std::unique_ptr<ClientRequest> New(std::shared_ptr<IAuthorization> authorization, 
			std::shared_ptr<Data::ICommand> command,
			SerializationGroup_Constructor serialization_group_constructor);

		static std::unique_ptr<ClientRequest> New(Data::IContainer Serialization,
			SerializationGroup_Constructor serialization_group_constructor);
	};
} 