#pragma once
#include "../Communication/Create.h"
#include "../Tamagotchi/Create.h"

namespace Server {
	class Server : public Communicators::IResponder
	{
		std::unique_ptr<Communicators::IResponder> responder;
		std::unique_ptr<Tamagotchi::ITamagotchi> tamagotchi;
		std::string tamagotchi_file_path;
		bool should_continue;
	public:
		Server();
		
		void Start();
	};

	std::string getAuthorizationString(uint8_t authbyte);
}