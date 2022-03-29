#pragma once
#include "Status.h"

Data::IContainer newStatusPayload(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	Data::IContainer result;
	result.push_front((Happiness << 4) | (Alertness << 4 >> 4));
	result.push_back((Cleanliness << 4) | (StomachLevel << 4 >> 4));

	return result;
}

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
	: Payload(newStatusPayload(Happiness, Alertness, Cleanliness, StomachLevel))
{
	
}

Data::Status::Status(Data::IContainer Serialization)
{
	this->Payload = Data::IContainer{Serialization[0], Serialization[1]};	
}

void Data::Status::setHappiness(uint8_t happiness)
{
	
}

void Data::Status::setAlertness(uint8_t alertness)
{
}

void Data::Status::setStomachLevel(uint8_t stomach)
{
}

void Data::Status::setCleaniness(uint8_t cleaniness)
{
}

Data::IContainer Data::Status::Serialize()
{
	return this->Payload;
}