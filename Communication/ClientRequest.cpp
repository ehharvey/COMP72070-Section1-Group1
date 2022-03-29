#pragma once
#include "ClientRequest.h"
#include "SerializationGroup.h"

Data::ClientRequest::ClientRequest()
{
	
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, CommandAction command)
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

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New()
{
	return std::unique_ptr<ClientRequest>();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(uint8_t authbyte, CommandAction command)
{
	return std::unique_ptr<ClientRequest>();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(Data::IContainer Serialization)
{
	return std::unique_ptr<ClientRequest>();
}