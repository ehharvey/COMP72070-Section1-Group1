#pragma once
#include "ServerResponse.h"

Data::ServerResponse::ServerResponse(std::unique_ptr<IStatus> status, std::unique_ptr<ICommand> command,
	std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc)
{
	this->serialization_group_constructor = sgc;
	this->status = std::move(status);
	this->command = std::move(command);
	this->result = std::move(result);
}

Data::ServerResponse::ServerResponse(std::unique_ptr<Music> music, Data::SerializationGroup_Constructor sgc)
{
	this->music = std::move(music);
	this->serialization_group_constructor = sgc;
}

Data::ServerResponse::ServerResponse(std::unique_ptr<Data::IResult> result, Data::SerializationGroup_Constructor sgc)
{
	this->result = std::move(result);
	this->serialization_group_constructor = sgc;
}


Data::ServerResponse::ServerResponse(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc)
{
	this->serialization_group_constructor = sgc;
	auto deserializer = this->serialization_group_constructor();
	auto deserialization = deserializer->Deserialize(Serialization);

	bool result_found = false;
	bool status_found = false;
	bool command_found = false;
	bool music_found = false;
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

		if ((!command_found))
		{
			// Attempt to get animation
			try
			{
				dynamic_cast<ICommand&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<ICommand> c = std::dynamic_pointer_cast<ICommand>(test);
				this->command = std::move(c);
				command_found = true;
				continue;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		
		if ((!music_found))
		{
			// Attempt to get animation
			try
			{
				dynamic_cast<Music&>(*item); // Can throw
				std::shared_ptr<ISerializable> test = std::move(item);
				std::shared_ptr<Music> c = std::dynamic_pointer_cast<Music>(test);
				this->music = std::move(c);
				music_found = true;
				continue;
			}
			catch(const std::exception& e)
			{
				// Do nothing
			}
		}

		if (status_found && command_found && result_found && music_found)
		{
			break;
		}
	}
}

std::optional<Data::IStatus*> 
Data::ServerResponse::getTamagotchiStatus() const
{
	if (this->status != nullptr)
		return this->status.get();
	else
		return  {} ;
}

std::optional<Data::ICommand*> 
Data::ServerResponse::getCurrentCommand() const
{
	if (this->command != nullptr)
		return this->command.get();
	else
		return  {} ;
}

std::optional<Data::IResult*> 
Data::ServerResponse::getResult() const
{
	if (this->result != nullptr)
		return this->result.get();
	else
		return  {} ;
}

Data::IContainer Data::ServerResponse::Serialize() const
{
	auto result = this->serialization_group_constructor();
	if (this->getCurrentCommand().has_value())
	{
		result->add(*this->getCurrentCommand().value());
	}
	if (this->getResult().has_value())
	{
		result->add(*this->getResult().value());
	}
	if (this->getTamagotchiStatus().has_value())
	{
		result->add(*this->getTamagotchiStatus().value());
	}
	if (this->getMusic().has_value())
	{
		result->add(*this->getMusic().value());
	}
	return result->Serialize();
}


std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization, sgc));
}

std::unique_ptr<Data::ServerResponse> 
Data::ServerResponse::New
(std::unique_ptr<IStatus> status, std::unique_ptr<ICommand> command,
	std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(std::move(status), 
		std::move(command), std::move(result), sgc));
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New(std::unique_ptr<Music> music, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<ServerResponse>(ServerResponse(std::move(music), sgc));
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New(std::unique_ptr<Data::IResult> result, Data::SerializationGroup_Constructor sgc)
{
	return std::make_unique<ServerResponse>(ServerResponse(std::move(result), sgc));
}


std::optional<Data::Music*>
Data::ServerResponse::getMusic() const
{
	if (this->music == nullptr)
		return {};
	else
		return this->music.get();
}