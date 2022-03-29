#pragma once
#include "CommandAction.h"
#include "IAnimation.h"
#include "IServerResponse.h"

namespace Data
{
    class ServerResponse : public IServerResponse {
	private:
		std::shared_ptr<IStatus> status;
		std::shared_ptr<IAnimation> animation;
	public:
		// "Traditional" constructors: do not use!
		ServerResponse();
		ServerResponse(const std::vector<uint8_t> Serialization);
		
		bool AuthSuccess();
		std::shared_ptr<CommandAction> getCurrentTamagotchiCommand();
		std::shared_ptr<IStatus> getTamagotchiStatus();
		std::shared_ptr<ISerializable> getAnimation();
		std::shared_ptr<ISerializable> getResult();
		const std::vector<uint8_t> Serialize();

		// Our "constructors"
		static std::unique_ptr<ServerResponse> New();
		static std::unique_ptr<ServerResponse> New(const std::vector<uint8_t> Serialization);
	};
} // namespace Data
