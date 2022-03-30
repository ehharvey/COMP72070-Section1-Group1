#pragma once
#include <memory>
#include "Server.h"

// Example usage:
// #include "../Server/Server.h"
// 
// ...
// auto server = Create::Server();
namespace Create
{
	// Server:: (from Server.h)
	std::unique_ptr<Server::Server> Server();
	std::unique_ptr<Server::Server> Server(std::unique_ptr<Communicators::IResponder> responder);
}