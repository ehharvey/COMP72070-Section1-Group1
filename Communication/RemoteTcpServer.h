#pragma once
#include "IContainer.h"
#include "rPtr.h"
#include "IRemoteResponder.h"
#include "IPV4Address.h"
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

namespace Communicators
{
    // This class is used by clients in order to connect to remote TCP servers
	class RemoteTcpServer : public IRemoteResponder
	{
	private:
		Data::IPV4Address address;
		rPtr send_function;
	public:
		RemoteTcpServer(Data::IPV4Address address);

		// Returns a function that you can use to connect to this server
		Data::IContainer GetResponse(Data::IContainer request) const;

		~RemoteTcpServer();
	};
} // namespace Communicators
