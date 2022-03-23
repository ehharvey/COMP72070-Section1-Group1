#pragma once
#include <string>
#include <memory>
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Client {
	__interface IClient
	{
		std::unique_ptr<Communication::IServerResponse> SendCommand(std::unique_ptr<Communication::IClientRequest> ClientRequest);
	};

	class Client : public IClient {
	private:
		std::unique_ptr<Communication:: 

		// To be removed
		Communication::ICommunicator& Communicator;

	public:
		Client(Communication::ICommunicator& Communicator);
		Communication::IServerResponse& SendCommand(Communication::IClientRequest& ClientRequest);
	};
}

namespace ClientMocks {
	class MockClient : public Client::IClient {
	public:
		MOCK_METHOD(Communication::IServerResponse&, SendCommand, (Communication::IClientRequest&));
	};
}
