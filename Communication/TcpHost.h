#pragma once
#include "IContainer.h"
#include "IPV4Address.h"
#include "IResponder.h"
#include <thread>
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")


namespace Communicators
{
    // This class is used by server apps in order to start their own TCP server
	class TcpHost : public IResponder
	{
	private:
		rPtr response_function;
		SOCKET server_socket;
		std::thread running_thread;
	public:
		TcpHost(rPtr response_function);

		void Start();
	};
} // namespace Communicators
