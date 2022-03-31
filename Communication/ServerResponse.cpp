#pragma once
#include "ServerResponse.h"


Data::ServerResponse::ServerResponse(Data::IContainer Serialization)
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

Data::IContainer Data::ServerResponse::Serialize()
{
	return this->serialization_group_constructor()
		->add(this->getAnimation())
		->add(this->getResult())
		->add(this->getTamagotchiStatus())
		->Serialize();
}


std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(Data::IContainer Serialization)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization));
}