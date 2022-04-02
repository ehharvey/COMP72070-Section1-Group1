#include "Create.h"

// Data:: (from Communication.h)
std::unique_ptr<Data::ClientRequest> Create::ClientRequest(std::shared_ptr<Data::IAuthorization> authorization, std::shared_ptr<Data::ICommand> command)
{
	return Data::ClientRequest::New(authorization, command, serializationGroupConstructors);
}

std::unique_ptr<Data::ClientRequest> Create::ClientRequest(Data::IContainer Serialization)
{
	return Data::ClientRequest::New(Serialization, serializationGroupConstructors);
}

std::unique_ptr<Data::ClientRequest> Create::DeserializeClientRequest(Data::IContainer Serialization) { return Create::ClientRequest(Serialization); }

std::unique_ptr<Data::ServerResponse> Create::ServerResponse(std::unique_ptr<Data::IStatus> status, std::unique_ptr<Data::IAnimation> animation,
	std::unique_ptr<Data::IResult> result)
{
	return Data::ServerResponse::New(std::move(status), std::move(animation), std::move(result), serializationGroupConstructors);
}

std::unique_ptr<Data::ServerResponse> Create::ServerResponse(Data::IContainer Serialization)
{
	return Data::ServerResponse::New(Serialization, serializationGroupConstructors);
}

std::unique_ptr<Data::Status> Create::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	return Data::Status::New(Happiness, Alertness, Cleanliness, StomachLevel);
}


std::unique_ptr<Data::Status> Create::Status(Data::IContainer Serialization)
{
	return Data::Status::New(Serialization);
}



// Comunicators:: (from Communication.h)
// To initialize:
// - auto IP = Data::IPV4Address { 192, 168, 2, 100 }
// - auto remote = Create::RemoteTcpServer(IP);
// 
//  (or)
// 
// - auto remote = Create::RemoteTcpServer({192, 168, 1, 100});
std::unique_ptr<Communicators::RemoteTcpServer> Create::RemoteTcpServer(Data::IPV4Address address)
{
	return std::make_unique<Communicators::RemoteTcpServer>(Communicators::RemoteTcpServer(address));
}

std::unique_ptr<Communicators::TcpHost> Create::TcpHost(Communicators::rPtr response_function)
{
	return std::make_unique<Communicators::TcpHost>(response_function);
}

std::unique_ptr<Data::Command> Create::Command(Data::IContainer Serialization)
{
	return std::make_unique<Data::Command>(Data::Command(Serialization));
}

std::unique_ptr<Data::Command> Create::Command(Data::CommandAction action)
{
	return std::make_unique<Data::Command>(Data::Command(action));
}