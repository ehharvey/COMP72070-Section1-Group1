#pragma once
#include "CommandAction.h"
#include "IContainer.h"
#include <memory>
#include "IAnimation.h"
#include "ISerializable.h"
#include "IStatus.h"
namespace Data
{
	__interface IServerResponse : public ISerializable
	{
		bool AuthSuccess() const;
		CommandAction getCurrentTamagotchiCommand() const;
		IStatus& getTamagotchiStatus() const;
		IAnimation& getAnimation() const;
		ISerializable& getResult() const;
	};

}