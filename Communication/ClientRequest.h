#pragma once
#include <memory>
#include "IContainer.h"
#include "IClientRequest.h"
#include "ICommand.h"
#include "IAuthorization.h"
#include "ISerializable.h"

namespace Data
{
    class ClientRequest : public IClientRequest {
	private:
		// CommandBuilder __command_creator;
		std::shared_ptr<IAuthorization> authorization;
		std::shared_ptr<ICommand> command;
		
		ClientRequest(std::shared_ptr<IAuthorization> authorization, std::shared_ptr<Data::ICommand> command);
		ClientRequest(Data::IContainer Serialization);
	public:
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();

		Data::IContainer Serialize();

		// Use these "constructors"
		static std::unique_ptr<ClientRequest> New(std::shared_ptr<IAuthorization> authorization, std::shared_ptr<Data::ICommand> command);
		static std::unique_ptr<ClientRequest> New(Data::IContainer Serialization);
	};
} 