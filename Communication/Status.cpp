#pragma once
#include "Status.h"

std::array<uint8_t, 2> newStatusPayload(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	std::array<uint8_t, 2> result;
	result[0] = ((Happiness << 4) | (Alertness << 4 >> 4));
	result[1] = ((Cleanliness << 4) | (StomachLevel << 4 >> 4));

	return result;
}

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
	: Payload(newStatusPayload(Happiness, Alertness, Cleanliness, StomachLevel))
{
	
}

Data::Status::Status(Data::IContainer Serialization)
{
	this->Payload[0] = Serialization.front();
	Serialization.pop_front();
	this->Payload[1] = Serialization.front();
	Serialization.pop_front();

	// Assert Serialization is empty
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
	return Data::IContainer(this->Payload.begin(), this->Payload.end());
}

std::unique_ptr<Data::Status> Data::Status::New(Data::IContainer Serialization)
{
	return std::make_unique<Status>(Data::Status(Serialization));
}

std::unique_ptr<Data::Status> Data::Status::New(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	return std::make_unique<Status>(Data::Status(Happiness, Alertness, Cleanliness, StomachLevel));
}
