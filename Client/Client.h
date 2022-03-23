#pragma once
#include <string>
#include <memory>
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Client {
	__interface IClient
	{
		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr<Data::IClientRequest> request);
	};

	class Client : public IClient {
	private:
		std::unique_ptr<Communicators::Sender> sender;

	public:
		Client();
		Client(std::unique_ptr<Communicators::Sender> sender);
		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr < Data::IClientRequest> request);
	};
}

namespace ClientMocks {
	class MockClient : public Client::IClient {
	public:
		MOCK_METHOD(std::unique_ptr<Data::IServerResponse>, SendCommand, (std::unique_ptr<Data::IClientRequest>));
	};
}
