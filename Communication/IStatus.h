#pragma once
#include "IContainer.h"
#include "ISerializable.h"

namespace Data
{
    __interface IStatus : public ISerializable
	{
		uint8_t getHappiness() const;
		uint8_t getAlertness() const;
		uint8_t getStomachLevel() const;
		uint8_t getCleaniness() const;
	};
}