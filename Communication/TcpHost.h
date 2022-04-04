#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#pragma once
#include "IContainer.h"
#include "IPV4Address.h"
#include "IResponder.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>


namespace Communicators
{
    // This class is used by server apps in order to start their own TCP server
	class TcpHost : public IResponder
	{
	private:
		rPtr response_function;
	public:
		TcpHost(rPtr response_function);

		void Start();
	};
} // namespace Communicators
