#pragma once
#include "IContainer.h"
#include "ICommand.h"
#include "IServerResponse.h"
#include "ISerializationGroup.h"
#include "Music.h"

namespace Data
{
    class ServerResponse : public IServerResponse {
	private:
		Data::SerializationGroup_Constructor serialization_group_constructor;
		
		std::shared_ptr<IResult> result;
		std::shared_ptr<IStatus> status;
		std::shared_ptr<ICommand> command;
		std::shared_ptr<Music> music;

		// "Traditional" constructors: do not use!
		ServerResponse(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc);
		ServerResponse(std::unique_ptr<IStatus> status, std::unique_ptr<ICommand> command,
			std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc);
		ServerResponse(std::unique_ptr<Music> music, Data::SerializationGroup_Constructor sgc);
		ServerResponse(std::unique_ptr<Data::IResult> result, Data::SerializationGroup_Constructor sgc);
	public:

		std::optional<IStatus*> getTamagotchiStatus() const; // optional does not work with aliases :(
		std::optional<ICommand*> getCurrentCommand() const;
		std::optional<IResult*> getResult() const; // Contains authentication status and any commands
		Data::IContainer Serialize () const;
		std::optional<Music*> getMusic() const;

		// Our "constructors"
		static std::unique_ptr<ServerResponse> New(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc);
		static std::unique_ptr<ServerResponse> New(std::unique_ptr<IStatus> status, std::unique_ptr<ICommand> command,
			std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc);
		static std::unique_ptr<ServerResponse> New(std::unique_ptr<Music> music, Data::SerializationGroup_Constructor sgc);
		static std::unique_ptr<ServerResponse> New(std::unique_ptr<Data::IResult> result, Data::SerializationGroup_Constructor sgc);

	};
} // namespace Data
