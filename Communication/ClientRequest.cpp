#pragma once
#include "ClientRequest.h"
#include "SerializationGroup.h"

Data::ClientRequest::ClientRequest()
{
	
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, CommandAction command)
{
	
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
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

const std::vector<uint8_t> Data::ClientRequest::Serialize()
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

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(const std::vector<uint8_t> Serialization)
{
	return std::unique_ptr<ClientRequest>();
}