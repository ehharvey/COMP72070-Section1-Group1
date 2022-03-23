#pragma once

#include "../Client/Client.h"
#include "../Communication/Communication.h"
#include <memory>

namespace Create
{
	std::unique_ptr<Client::Client> Client(Communication::ICommunicator& Communicator);
}