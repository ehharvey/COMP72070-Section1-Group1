#pragma once
#include <string>
#include <memory>
#include "../Communication/Create.h"

namespace Client {
	__interface IClient
	{
		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr<Data::IClientRequest> request);
	};

	class Client : public IClient {
	private:
		std::unique_ptr<Communicators::ISender> sender;

	public:
		Client();
		Client(std::unique_ptr<Communicators::ISender> sender);
		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr < Data::IClientRequest> request);
	};
}