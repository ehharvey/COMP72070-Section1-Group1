#pragma once
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Server {
	const int EXPECTED_FOO = 3;
	int getFOO();

	__interface IServer
	{
		Communication::IClientRequest& ReceiveRequest();
	};

	class Server
	{
		Communication::ICommunicator& Communicator;
	public:
		Server(Communication::ICommunicator& Communicator);
		Communication::ClientRequest ReceiveRequest();
	};

}

namespace ServerMocks {

}