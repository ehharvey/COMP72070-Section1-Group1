#pragma once
#include "CommandAction.h"
#include "IContainer.h"
#include <memory>
#include "IAnimation.h"
#include "ISerializable.h"
#include "IResult.h"
#include "IStatus.h"
namespace Data
{
	__interface IServerResponse : public ISerializable
	{
		IStatus& getTamagotchiStatus() const;
		IAnimation& getAnimation() const;
		IResult& getResult() const;
	};

}