#pragma once
#include "ServerResponse.h"


Data::ServerResponse::ServerResponse(Data::IContainer Serialization)
{
	auto deserializer = this->serialization_group_constructor();
	auto deserialization = deserializer->Deserialize(Serialization);

	bool result_found = false;
	bool status_found = false;
	bool animation_found = false;
	for (auto item = deserialization->getNext(); item != nullptr; 
		 item = deserialization->getNext())
	{
		// Attempt to retrieve Result
		if (!result_found)
		{
			try
			{
				dynamic_cast<IResult&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<IResult> c = std::dynamic_pointer_cast<IResult>(test);
				this->result = std::move(c);
				result_found = true;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		// Attempt to retrieve status
		if (!status_found)
		{
			try
			{
				dynamic_cast<IStatus&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<IStatus> c = std::dynamic_pointer_cast<IStatus>(test);
				this->status = std::move(c);
				status_found = true;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		if ((!animation_found))
		{
			// Attempt to get animation
			try
			{
				dynamic_cast<IAnimation&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<IAnimation> c = std::dynamic_pointer_cast<IAnimation>(test);
				this->animation = std::move(c);
				animation_found = true;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		if (status_found && animation_found)
			{
				break;
			}
	}
}

Data::IStatus& 
Data::ServerResponse::getTamagotchiStatus() const
{
	return *this->status;
}

Data::IAnimation& 
Data::ServerResponse::getAnimation() const
{
	return *this->animation;
}

Data::IResult& 
Data::ServerResponse::getResult() const
{
	return *this->result;
}

Data::IContainer Data::ServerResponse::Serialize() const
{
	return this->serialization_group_constructor()
		->add(this->getAnimation())
		->add(this->getResult())
		->add(this->getTamagotchiStatus())
		->Serialize();
}


std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(Data::IContainer Serialization)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization));
}