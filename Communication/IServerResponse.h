#pragma once
#include <memory>
#include "IAnimation.h"
#include "ISerializable.h"
#include "IStatus.h"
namespace Data
{
	__interface IServerResponse : public ISerializable
	{
		bool AuthSuccess();
		std::shared_ptr<IStatus> getTamagotchiStatus();
		std::shared_ptr<ISerializable> getAnimation();
		std::shared_ptr<ISerializable> getResult();
	};

}