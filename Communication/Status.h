#pragma once
#include <memory>
#include "IStatus.h"

namespace Data
{
    class Status : public IStatus {
		// Payload format
		// hhhh aaaa [happiness alertness]
		// ssss cccc [stomach cleaniness]
		std::vector<uint8_t> Payload; // 2 bytes
	public:
		Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		Status(const std::vector<uint8_t> Serialization);

		uint8_t getHappiness() { return Payload[0] >> 4; };
		uint8_t getAlertness() { return Payload[0] << 4 >> 4; };
		uint8_t getStomachLevel() { return Payload[1] >> 4; };
		uint8_t getCleaniness() { return Payload[1] << 4 >> 4; };

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);

		const std::vector<uint8_t> Serialize();

		// Our "constructors"
		static std::unique_ptr<Status> New(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		static std::unique_ptr<Status> New(uint16_t Payload);
		static std::unique_ptr<Status> New(const std::vector<uint8_t> Serialization);
	};
} // namespace Data
