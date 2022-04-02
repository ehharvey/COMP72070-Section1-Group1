#pragma once
#include "ServerResponse.h"

Data::ServerResponse::ServerResponse(std::unique_ptr<IStatus> status, std::unique_ptr<IAnimation> animation,
	std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc)
{
	this->serialization_group_constructor = sgc;
	this->status = std::move(status);
	this->animation = std::move(animation);
	this->result = std::move(result);
}


Data::ServerResponse::ServerResponse(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc)
{
	this->serialization_group_constructor = sgc;
	auto deserializer = this->serialization_group_constructor();
	auto deserialization = deserializer->Deserialize(Serialization);

	bool result_found = false;
	bool status_found = false;
	bool animation_found = false;
	for (auto item = deserialization->getNext(); item != nullptr; 
		 item = deserialization->getNext())
	{
		std::cout << std::type_index(typeid(item)).name();
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
				continue;
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
				continue;
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
				continue;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		if (status_found && animation_found && result_found)
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
(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization, sgc));
}

std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(std::unique_ptr<IStatus> status, std::unique_ptr<IAnimation> animation,
	std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(std::move(status), 
		std::move(animation), std::move(result), sgc));
}