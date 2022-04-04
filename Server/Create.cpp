#include "Create.h"

// Server:: (from Server.h)
std::unique_ptr<Server::Server> Create::Server()
{
	return std::make_unique<Server::Server>(Server::Server());
}

std::unique_ptr<Server::Server> Create::Server(std::unique_ptr<Communicators::IResponder> responder)
{
	return std::make_unique<Server::Server>(Server::Server());
}
