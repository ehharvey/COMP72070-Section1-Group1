#include "Create.h"

std::unique_ptr<Client::Client> Create::Client()
{
    return std::make_unique<Client::Client>(Client::Client());
}

std::unique_ptr<Client::Client> Create::Client(std::unique_ptr<Communicators::ISender> sender)
	{
		return std::make_unique<Client::Client>(Client::Client(std::move(sender)));
	}