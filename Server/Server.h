#pragma once
#include "../Communication/Communication.h"

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