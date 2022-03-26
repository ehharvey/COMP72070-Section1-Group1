#include "Create.h"

namespace Create {
	// Client (from Client.h
	std::unique_ptr<Client::Client> Client()
	{
		return std::make_unique<Client::Client>(Client::Client());
	}

	std::unique_ptr<Client::Client> Client(std::unique_ptr<Communicators::ISender> sender)
	{
		return std::make_unique<Client::Client>(Client::Client(std::move(sender)));
	}
}