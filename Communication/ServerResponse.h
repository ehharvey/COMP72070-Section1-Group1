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
		
		std::shared_ptr<IResult> result;
		std::shared_ptr<IStatus> status;
		std::shared_ptr<IAnimation> animation;

		// "Traditional" constructors: do not use!
		ServerResponse(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc);
		ServerResponse(std::unique_ptr<IStatus> status, std::unique_ptr<IAnimation> animation,
			std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc);
	public:		
		IStatus& getTamagotchiStatus() const;
		IAnimation& getAnimation() const;
		IResult& getResult() const; // Contains authentication status and any commands
		Data::IContainer Serialize () const;

		// Our "constructors"
		// TODO: More constructors, Result implementation
		static std::unique_ptr<ServerResponse> New(Data::IContainer Serialization, Data::SerializationGroup_Constructor sgc);
		static std::unique_ptr<ServerResponse> New(std::unique_ptr<IStatus> status, std::unique_ptr<IAnimation> animation,
			std::unique_ptr<IResult> result, Data::SerializationGroup_Constructor sgc);

	};
} // namespace Data
