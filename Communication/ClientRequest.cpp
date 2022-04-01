#pragma once
#include "ClientRequest.h"


Data::ClientRequest::ClientRequest(std::shared_ptr<IAuthorization> authorization, 
			std::shared_ptr<Data::ICommand> command,
			SerializationGroup_Constructor serialization_group_constructor)
: authorization(authorization), 
command(command), 
serialization_group_constructor(serialization_group_constructor)
{
	
}

Data::ClientRequest::ClientRequest
(Data::IContainer Serialization, SerializationGroup_Constructor serialization_group_constructor)
: serialization_group_constructor(serialization_group_constructor)
{
	auto deserialization = this->serialization_group_constructor()
		->Deserialize(Serialization);

	bool authorization_found = false;
	bool command_found = false;
	for (auto & item : deserialization)
	{
		
		// Attempt to retrieve authorization
		if (!authorization_found)
		{
			try
			{
				dynamic_cast<IAuthorization&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<IAuthorization> c = std::dynamic_pointer_cast<IAuthorization>(test);

				authorization_found = true;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}

			try
			{
				dynamic_cast<ICommand&>(*item); // Can throw
				
				command_found = true;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}

			if (authorization_found && command_found)
			{
				break;
			}
		}
		
		
	}
	
}

Data::IAuthorization& Data::ClientRequest::getAuthorization() const
{
	return *this->authorization;
}

Data::ICommand& Data::ClientRequest::getCommand() const
{
	return *(this->command);
}

Data::IContainer Data::ClientRequest::Serialize() const
{
	return this->serialization_group_constructor()->
		 add(this->getAuthorization())
		.add(this->getCommand())
		.Serialize();
}

std::unique_ptr<Data::ClientRequest> 
Data::ClientRequest::New
(std::shared_ptr<IAuthorization> authorization, 
	std::shared_ptr<Data::ICommand> command,
	SerializationGroup_Constructor serialization_group_constructor)
{
	return std::make_unique<ClientRequest>(ClientRequest(
		authorization, 
		command,
		serialization_group_constructor
	));
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(Data::IContainer Serialization,
			SerializationGroup_Constructor serialization_group_constructor)
{
	return std::make_unique<ClientRequest>(ClientRequest(
		Serialization,
		serialization_group_constructor
	));
}