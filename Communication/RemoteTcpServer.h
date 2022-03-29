#pragma once
#include "rPtr.h"
#include "IRemoteResponder.h"
#include "IPV4Address.h"

namespace Communicators
{
    // This class is used by clients in order to connect to remote TCP servers
	class RemoteTcpServer : public IRemoteResponder
	{
	private:
		Data::IPV4Address address;

	public:
		RemoteTcpServer(Data::IPV4Address address) :
			address(address)
		{ };

		// Returns a function that you can use to connect to this server
		rPtr getSendFunction();
	};
} // namespace Communicators
