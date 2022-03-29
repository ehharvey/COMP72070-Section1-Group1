#pragma once
#include <memory>
#include "IClientRequest.h"
#include "ICommand.h"
#include "IAuthorization.h"
#include "CommandAction.h"
#include "ISerializable.h"

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
		ClientRequest(const std::vector<uint8_t> Serialization);
		
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();

		const std::vector<uint8_t> Serialize();


		// Use these "constructors"
		static std::unique_ptr<ClientRequest> New();
		static std::unique_ptr<ClientRequest> New(uint8_t authbyte, CommandAction command);
		static std::unique_ptr<ClientRequest> New(const std::vector<uint8_t> Serialization);
	};
} 