#pragma once
#include "../Communication/Communication.h"

namespace Server {
	const int EXPECTED_FOO = 3;
	int getFOO();

	class Server
	{
		Communication::ICommunicator* Communicator;
	public:
		Communication::ClientRequest ReceiveRequest();
	};

}
