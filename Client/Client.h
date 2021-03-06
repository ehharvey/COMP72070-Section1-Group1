#pragma once
#include <string>
#include <memory>
#include <algorithm>
#include "../Communication/Create.h"

// A function that receives a uint8_t vector and returns a server response pointer
typedef std::function<std::unique_ptr<Data::IServerResponse>(Data::IContainer)> ResponseParser;

namespace Client {
	const ResponseParser default_parser = [](Data::IContainer response_serialization)
	{
		return Create::ServerResponse(response_serialization);
	};

	__interface IClient
	{
		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr<Data::IClientRequest> request);
	};


	class Client : public IClient {
	private:
		std::unique_ptr<Communicators::IRemoteResponder> remote;
		
		ResponseParser response_parser;
	public:
		Client();
		Client(std::unique_ptr<Communicators::IRemoteResponder> remote);;

		void __setResponseParser(ResponseParser rp);

		std::unique_ptr<Data::IServerResponse> SendCommand(std::unique_ptr <Data::IClientRequest> request);

		static std::unique_ptr<Client> New();
	};
}