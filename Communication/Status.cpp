#pragma once
#include "Status.h"
#include <iostream>

std::array<uint8_t, 2> newStatusPayload(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	std::array<uint8_t, 2> result;
	result[0] = ((Happiness << 4) | (Alertness << 4 >> 4));
	result[1] = ((Cleanliness << 4) | (StomachLevel << 4 >> 4));

	return result;
}

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
	: Payload(newStatusPayload(Happiness, Alertness, Cleanliness, StomachLevel))
{ }

Data::Status::Status(Data::IContainer Serialization)
{
	
	switch (Serialization.size())
	{
	case 0:
		std::cerr << "Status: Did not receive any bytes!";
		break;
	case 1:
		std::cerr << "Status: Did not receive enough bytes!";
		this->Payload = {0, 0};
		break;
	case 2:
		this->Payload[0] = Serialization.front();
		Serialization.pop_front();
		this->Payload[1] = Serialization.front();
		Serialization.pop_front();
		break;
	default:
		std::cerr << "Authorization: Received more than 2 bytes!";
		this->Payload = {0, 0};
		break;
	}
	// Assert Serialization is empty
}

void Data::Status::setHappiness(uint8_t happiness)
{
	uint8_t adjusted = happiness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : happiness;
	this->Payload = newStatusPayload(adjusted, this->getAlertness(), this->getCleaniness(), this->getStomachLevel());
}

void Data::Status::setAlertness(uint8_t alertness)
{
	uint8_t adjusted = alertness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : alertness;
	this->Payload = newStatusPayload(this->getHappiness(), adjusted, this->getCleaniness(), this->getStomachLevel());
}

void Data::Status::setStomachLevel(uint8_t stomach)
{
	uint8_t adjusted = stomach > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : stomach;
	this->Payload = newStatusPayload(this->getHappiness(), this->getAlertness(), this->getCleaniness(), adjusted);
}

void Data::Status::setCleaniness(uint8_t cleaniness)
{
	uint8_t adjusted = cleaniness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : cleaniness;
	this->Payload = newStatusPayload(this->getHappiness(), this->getAlertness(), cleaniness, this->getStomachLevel());
}

Data::IContainer Data::Status::Serialize() const
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
