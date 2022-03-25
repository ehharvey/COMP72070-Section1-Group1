#pragma once
#include <memory>
#include "Server.h"

namespace Create
{
	// Server:: (from Server.h)
	std::unique_ptr<Server::Server> Server()
	{
		return std::make_unique<Server::Server>(Server::Server());
	}
	std::unique_ptr<Server::Server> Server(std::unique_ptr<Communicators::IResponder> responder)
	{
		return std::make_unique<Server::Server>(Server::Server(std::move(responder)));
	}
}