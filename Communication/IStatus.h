#pragma once
#include "IContainer.h"
#include "ISerializable.h"

namespace Data
{
	const uint8_t MAX_STAT_LEVEL = 15;

    __interface IStatus : public ISerializable
	{
		uint8_t getHappiness() const;
		uint8_t getAlertness() const;
		uint8_t getStomachLevel() const;
		uint8_t getCleaniness() const;

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);
	};
}