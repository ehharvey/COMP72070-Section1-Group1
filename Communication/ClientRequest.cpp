#pragma once
#include "ClientRequest.h"
#include "SerializationGroup.h"


Data::ClientRequest::ClientRequest(std::shared_ptr<IAuthorization> authorization, 
	std::shared_ptr<Data::ICommand> command)
	: authorization(authorization), command(command)
{
	
}

Data::ClientRequest::ClientRequest(Data::IContainer Serialization)
{
	// First byte is authbyte
	
}

std::shared_ptr<Data::ISerializable> Data::ClientRequest::getAuthorization()
{
	return this->authorization;
}

// #StillAStub
std::shared_ptr<Data::ICommand> Data::ClientRequest::getCommand()
{
	return this->command;
}

Data::IContainer Data::ClientRequest::Serialize()
{
	return SerializationGroup::New()
		->add(this->getAuthorization())
		->add(this->getCommand())
		->Serialize();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(std::shared_ptr<IAuthorization> authorization, \
std::shared_ptr<Data::ICommand> command)
{
	return std::unique_ptr<ClientRequest>();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(Data::IContainer Serialization)
{
	return std::unique_ptr<ClientRequest>();
}