#pragma once
#include "IContainer.h"
#include "rPtr.h"

namespace Communicators
{
    __interface IRemoteResponder
	{
		// Returns a function that you can use to connect to this server
		Data::IContainer GetResponse(Data::IContainer request) const;
	};

} // namespace 
