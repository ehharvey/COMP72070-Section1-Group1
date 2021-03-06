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
	: Happiness(Happiness), Alertness(Alertness), Cleanliness(Cleanliness), StomachLevel(StomachLevel)
{}

Data::Status::Status(Data::IContainer Serialization)
{
	
	switch (Serialization.size())
	{
	case 0:
	case 1:
	case 2:
	case 3:
		std::cerr << "Status: Did not receive any bytes!";
		break;
	case 4:
		// Order: h a c s

		this->Happiness = Serialization.front();
		Serialization.pop_front();
		this->Alertness = Serialization.front();
		Serialization.pop_front();
		this->Cleanliness = Serialization.front();
		Serialization.pop_front();
		this->StomachLevel = Serialization.front();
		Serialization.pop_front();
		break;
	default:
		std::cerr << "Authorization: Received more than 4 bytes!";
		
		break;
	}
	// Assert Serialization is empty
}

uint8_t Data::Status::getHappiness() const
{
	return this->Happiness;
}

uint8_t Data::Status::getAlertness() const
{
	return this->Alertness;
}

uint8_t Data::Status::getStomachLevel() const
{
	return this->StomachLevel;
}

uint8_t Data::Status::getCleaniness() const
{
	return this->Cleanliness;
}

void Data::Status::setHappiness(uint8_t happiness)
{
	uint8_t adjusted = happiness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : happiness;
	this->Happiness = adjusted;
}

void Data::Status::setAlertness(uint8_t alertness)
{
	uint8_t adjusted = alertness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : alertness;
	this->Alertness = adjusted;
}

void Data::Status::setStomachLevel(uint8_t stomach)
{
	uint8_t adjusted = stomach > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : stomach;
	this->StomachLevel = adjusted;
}

void Data::Status::setCleaniness(uint8_t cleaniness)
{
	uint8_t adjusted = cleaniness > MAX_STAT_LEVEL ? MAX_STAT_LEVEL : cleaniness;
	this->Cleanliness = adjusted;
}

Data::IContainer Data::Status::Serialize() const
{
	return Data::IContainer({Happiness, Alertness, Cleanliness, StomachLevel});
}

std::unique_ptr<Data::Status> Data::Status::New(Data::IContainer Serialization)
{
	return std::make_unique<Status>(Data::Status(Serialization));
}

std::unique_ptr<Data::Status> Data::Status::New(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	return std::make_unique<Status>(Data::Status(Happiness, Alertness, Cleanliness, StomachLevel));
}
