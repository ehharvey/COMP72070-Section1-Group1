#pragma once
#include "IContainer.h"
#include "ISerializable.h"

namespace Data
{
    __interface IStatus : public ISerializable
	{
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getCleaniness();
	};
}