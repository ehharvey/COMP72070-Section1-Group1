#pragma once
#include "../Communication/Communication.h"
#include "gmock/gmock.h"

namespace Server {
	class Server : public Communicators::IResponder
	{
		std::unique_ptr<Communicators::IResponder> responder;
	public:
		Server();
		Server(std::unique_ptr<Communicators::IResponder> responder);
		
		void Start();
		bool getIsRunning();
		void Stop();
		void RegisterResponse(Communicators::rPtr);
	};

}

// As Server is itself a Communicators::Responder, we can mock it via Mocks::ResponderMock
namespace Mocks
{
	typedef Mocks::ResponderMock ServerMock;
}