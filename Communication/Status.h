#pragma once
#include "IContainer.h"
#include <memory>
#include <array>
#include <typeindex>
#include <utility>
#include "IStatus.h"

namespace Data
{
    class Status : public IStatus {
		uint8_t Happiness;
		uint8_t Alertness;
		uint8_t Cleanliness;
		uint8_t StomachLevel;


		Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		Status(Data::IContainer Serialization);

	public:
		uint8_t getHappiness() const;
		uint8_t getAlertness() const ;
		uint8_t getStomachLevel() const;
		uint8_t getCleaniness() const;

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);

		Data::IContainer Serialize () const;

		// Our "constructors"
		static std::unique_ptr<Status> New(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		static std::unique_ptr<Status> New(Data::IContainer Serialization);
	};

	auto const _DeserializeStatus = [](Data::IContainer Serialization) { return Status::New(Serialization); };

	const std::pair<std::type_index, Data::ISerializableConstructor> status_type_constructor =
		std::make_pair<std::type_index, Data::ISerializableConstructor>
		(std::type_index(typeid(Status)), _DeserializeStatus);
} // namespace Data
