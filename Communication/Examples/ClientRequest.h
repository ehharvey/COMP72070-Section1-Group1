#pragma once
#include "IContainer.h"
#include "IAuthorization.h"
#include "CommandAction.h"
#include "IClientRequest.h"

namespace Data
{
    class ClientRequest : public IClientRequest {
	private:
		// CommandBuilder __command_creator;
		std::shared_ptr<IAuthorization> authorization;
		std::shared_ptr<ICommand> command;
		
	public:
		ClientRequest();
		ClientRequest(uint8_t authbyte, CommandAction command);
		ClientRequest(Data::IContainer Serialization);
		
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();

		Data::IContainer Serialize () const;


		// Use these "constructors"
		static std::unique_ptr<ClientRequest> New();
		static std::unique_ptr<ClientRequest> New(uint8_t authbyte, CommandAction command);
		static std::unique_ptr<ClientRequest> New(Data::IContainer Serialization);
	};
} // namespace Data
