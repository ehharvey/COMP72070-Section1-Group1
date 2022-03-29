#pragma once
#include "Status.h"

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	uint8_t happiness_and_alertness = (Happiness << 4) | (Alertness << 4 >> 4);
	uint8_t cleanliness_and_stomach = (Cleanliness << 4) | (StomachLevel << 4 >> 4);
	this->Payload = {happiness_and_alertness, cleanliness_and_stomach};
}

Data::Status::Status(const std::vector<uint8_t> Serialization)
{
	this->Payload = std::vector<uint8_t>{Serialization[0], Serialization[1]};	
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

const std::vector<uint8_t> Data::Status::Serialize()
{
	return this->Payload;
}