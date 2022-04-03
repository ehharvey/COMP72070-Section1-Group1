#pragma once
#include "ICommand.h"
#include "IContainer.h"
#include "IAnimation.h"
#include "ISerializable.h"
#include "IResult.h"
#include "IStatus.h"
#include "Music.h"
#include <optional>

namespace Data
{
	__interface IServerResponse : public ISerializable
	{
		std::optional<IStatus*> getTamagotchiStatus() const; // optional does not work with aliases :(
		std::optional<ICommand*> getCurrentCommand() const;
		std::optional<IResult*> getResult() const; // Contains authentication status and any commands
		Data::IContainer Serialize () const;
		std::optional<Music*> getMusic() const;
	};

}