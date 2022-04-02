#pragma once
#include "ClientRequest.h"
#include <iostream>

Data::ClientRequest::ClientRequest(std::shared_ptr<IAuthorization> authorization, 
			std::shared_ptr<Data::ICommand> command,
			SerializationGroup_Constructor serialization_group_constructor)
: authorization(authorization), 
command(command), 
serialization_group_constructor(serialization_group_constructor)
{ }

Data::ClientRequest::ClientRequest
(Data::IContainer Serialization, SerializationGroup_Constructor serialization_group_constructor)
: serialization_group_constructor(serialization_group_constructor)
{
	std::cout << "ClientRequest(): deserializing\n";
	std::unique_ptr<ISerializationGroup> deserializer = this->serialization_group_constructor();
	auto deserialization = deserializer->Deserialize(Serialization);
	std::cout << "ClientRequest(): done\n";

	bool authorization_found = false;
	bool command_found = false;

	for (auto item = deserialization->getNext(); item != nullptr; 
		 item = deserialization->getNext())
	{
		std::cout << "ClientRequest(): processing deserialization\n";
		if (!authorization_found)
		{
			try
			{
				std::cout << "ClientRequest(): attempting to cast to auth\n";
				dynamic_cast<IAuthorization&>(*item); // Can throw
				std::cout << "ClientRequest(): done\n";
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<IAuthorization> c = std::dynamic_pointer_cast<IAuthorization>(test);
				this->authorization = std::move(c);

				authorization_found = true;
				std::cout << "ClientRequest(): authorization cast worked :)\n";
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}

			try
			{
				dynamic_cast<ICommand&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<ICommand> c = std::dynamic_pointer_cast<ICommand>(test);
				this->command = std::move(c);

				
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
	return this->serialization_group_constructor()
		->add(this->getAuthorization())
		->add(this->getCommand())
		->Serialize();
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