#pragma once
#include "../Communication/Create.h"

namespace Server {
	class Server : public Communicators::IResponder
	{
		std::unique_ptr<Communicators::IResponder> responder;
	public:
		Server();
		
		void Start();
		bool getIsRunning();
		void Stop();
	};

}