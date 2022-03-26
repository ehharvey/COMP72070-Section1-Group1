#pragma once
#include "Client.h"
#include <memory>

// Example usage:
// #include "../Client/Create.h"
// 
// ...
// auto tamagotchi = Create::Client();
namespace Create {
	// Client (from Client.h
	std::unique_ptr<Client::Client> Client();

	std::unique_ptr<Client::Client> Client(std::unique_ptr<Communicators::ISender> sender);
}