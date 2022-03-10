#pragma once
#include <string>
#include "../Communication/Communication.h"

namespace Client {
	const int EXPECTED_FOO = 3;

	int getFOO();

	class Client {
	private:
		Communication::ICommunicator& Communicator;

	public:
		Client(Communication::ICommunicator& Communicator);
		Communication::ServerResponse SendCommand(Communication::ClientRequest ClientRequest);
	};
}
