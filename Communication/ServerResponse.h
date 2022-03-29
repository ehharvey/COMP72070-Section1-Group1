#pragma once
#include "IContainer.h"
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
		ServerResponse(Data::IContainer Serialization);
		
		bool AuthSuccess();
		std::shared_ptr<CommandAction> getCurrentTamagotchiCommand();
		std::shared_ptr<IStatus> getTamagotchiStatus();
		std::shared_ptr<ISerializable> getAnimation();
		std::shared_ptr<ISerializable> getResult();
		Data::IContainer Serialize();

		// Our "constructors"
		static std::unique_ptr<ServerResponse> New();
		static std::unique_ptr<ServerResponse> New(Data::IContainer Serialization);
	};
} // namespace Data
