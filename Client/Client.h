#pragma once
#include <string>
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Client {
	const int EXPECTED_FOO = 3;

	int getFOO();

	__interface IClient
	{
		Communication::IServerResponse& SendCommand(Communication::IClientRequest& ClientRequest);
	};

	class Client : public IClient {
	private:
		Communication::ICommunicator& Communicator;

	public:
		Client(Communication::ICommunicator& Communicator);
		Communication::IServerResponse& SendCommand(Communication::IClientRequest& ClientRequest);
	};
}

namespace ClientMocks {
	class MockClient : public Client::IClient {
		MOCK_METHOD(Communication::IServerResponse&, SendCommand, (Communication::IClientRequest&));
	};
}
