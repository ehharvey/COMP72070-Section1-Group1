#pragma once
#include "IContainer.h"
#include "IPV4Address.h"
#include "IResponder.h"

namespace Communicators
{
    // This class is used by server apps in order to start their own TCP server
	class TcpHost : public IResponder
	{
	private:
		Data::IPV4Address address;
		rPtr response_function;
	public:
		TcpHost(Data::IPV4Address address, rPtr response_function) :
			address(address),
			response_function(response_function)
		{ };

		void Start();
		bool getIsRunning();
		void Stop();
		void RegisterResponse(rPtr response_function);

	};
} // namespace Communicators
