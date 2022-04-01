#pragma once
#include "IContainer.h"
#include "CommandAction.h"
#include "IAnimation.h"
#include "IServerResponse.h"
#include "ISerializationGroup.h"

namespace Data
{
    class ServerResponse : public IServerResponse {
	private:
		Data::SerializationGroup_Constructor serialization_group_constructor;
		
		std::shared_ptr<ISerializable> result;
		std::shared_ptr<IStatus> status;
		std::shared_ptr<IAnimation> animation;

		// "Traditional" constructors: do not use!
		ServerResponse(Data::IContainer Serialization);
	public:		
		bool AuthSuccess() const;
		CommandAction getCurrentTamagotchiCommand() const;
		IStatus& getTamagotchiStatus() const;
		IAnimation& getAnimation() const;
		ISerializable& getResult() const;
		Data::IContainer Serialize () const;

		// Our "constructors"
		// TODO: More constructors, Result implementation
		static std::unique_ptr<ServerResponse> New(Data::IContainer Serialization);
	};
} // namespace Data
