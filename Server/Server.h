#pragma once
#include "../Communication/Create.h"
#include "../Tamagotchi/Create.h"

namespace Server {
	class Server : public Communicators::IResponder
	{
		std::unique_ptr<Communicators::IResponder> responder;
		bool should_continue;
		
	public:
		Server();
		void setShouldContinue(bool b);
		void Start();
	};

	std::string getAuthorizationString(uint8_t authbyte);
}