#pragma once
#include "ServerResponse.h"
#include "SerializationGroup.h"

Data::ServerResponse::ServerResponse()
{
}

Data::ServerResponse::ServerResponse(const std::vector<uint8_t> Serialization)
{
}

bool Data::ServerResponse::AuthSuccess()
{
	return false;
}

std::shared_ptr<Data::CommandAction> Data::ServerResponse::getCurrentTamagotchiCommand()
{
	return std::shared_ptr<Data::CommandAction>();
}

std::shared_ptr<Data::IStatus> Data::ServerResponse::getTamagotchiStatus()
{
	return std::unique_ptr<IStatus>();
}

std::shared_ptr<Data::ISerializable> Data::ServerResponse::getAnimation()
{
	return std::unique_ptr<ISerializable>();
}

std::shared_ptr<Data::ISerializable> Data::ServerResponse::getResult()
{
	return std::shared_ptr<ISerializable>();
}

const std::vector<uint8_t> Data::ServerResponse::Serialize()
{
	return SerializationGroup::New()
		->add(this->getAnimation())
		->add(this->getResult())
		->add(this->getTamagotchiStatus())
		->Serialize();
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New()
{
	return std::unique_ptr<ServerResponse>();
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New(const std::vector<uint8_t> Serialization)
{
	return std::unique_ptr<ServerResponse>();
}