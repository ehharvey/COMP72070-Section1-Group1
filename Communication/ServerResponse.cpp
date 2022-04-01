#pragma once
#include "ServerResponse.h"


Data::ServerResponse::ServerResponse(Data::IContainer Serialization)
{
}

bool Data::ServerResponse::AuthSuccess() const
{
	return false;
}

Data::CommandAction
Data::ServerResponse::getCurrentTamagotchiCommand() const
{
	return Data::CommandAction::idle;
}

Data::IStatus& 
Data::ServerResponse::getTamagotchiStatus() const
{
	return *this->status;
}

Data::IAnimation& 
Data::ServerResponse::getAnimation() const
{
	return *this->animation;
}

Data::ISerializable& 
Data::ServerResponse::getResult() const
{
	return *this->result;
}

Data::IContainer Data::ServerResponse::Serialize() const
{
	return this->serialization_group_constructor()->
		 add(this->getAnimation())
		.add(this->getResult())
		.add(this->getTamagotchiStatus())
		.Serialize();
}


std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(Data::IContainer Serialization)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization));
}