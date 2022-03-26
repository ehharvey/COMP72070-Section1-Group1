#pragma once
#include "Client.h"
#include <memory>

namespace Create {
	// Client (from Client.h
	std::unique_ptr<Client::Client> Client();

	std::unique_ptr<Client::Client> Client(std::unique_ptr<Communicators::ISender> sender);
}