#include "pch.h"
#include "Create.h"

std::unique_ptr<Client::Client> Create::Client()
{
	return std::make_unique<Client::Client> (Client::Client());
}

std::unique_ptr<Client::Client> Create::Client(std::unique_ptr<Communicators::Sender> sender)
{
	return std::make_unique<Client::Client>(Client::Client(std::move(sender)));
}

std::unique_ptr<Data::ClientRequest> Create::ClientRequest()
{
	return std::make_unique<Data::ClientRequest>(Data::ClientRequest());
}

std::unique_ptr<Data::ClientRequest> Create::ClientRequest(const std::vector<uint8_t> Serialization)
{
	return std::make_unique<Data::ClientRequest>(Data::ClientRequest(Serialization));
}

std::unique_ptr<Data::ServerResponse> Create::ServerResponse()
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse());
}

std::unique_ptr<Data::ServerResponse> Create::ServerResponse(const std::vector<uint8_t> Serialization)
{
	return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization));
}

std::unique_ptr<Data::Status> Create::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	return std::make_unique<Data::Status>(Data::Status(Happiness, Alertness, Cleanliness, StomachLevel));
}

std::unique_ptr<Data::Status> Create::Status(uint16_t Payload)
{
	return std::make_unique<Data::Status>(Data::Status(Payload));
}

std::unique_ptr<Communicators::RemoteTcpServer> Create::RemoteTcpServer(Data::IPV4Address address)
{
	return std::make_unique<Communicators::RemoteTcpServer>(Communicators::RemoteTcpServer(address));
}

std::unique_ptr<Communicators::TcpHost> Create::TcpHost(Data::IPV4Address address, Communicators::rPtr response_function)
{
	return std::make_unique<Communicators::TcpHost>(Communicators::TcpHost(address, response_function));
}

std::unique_ptr<Communicators::TcpClient> Create::TcpClient(Data::IPV4Address address, std::unique_ptr<Communicators::RemoteResponder> remote)
{
	return std::make_unique<Communicators::TcpClient>(Communicators::TcpClient(address, std::move(remote)));
}

std::unique_ptr<Logger::Log> Create::Log(Logger::action action, const std::vector<uint8_t> data)
{
	return std::make_unique<Logger::Log>(Logger::Log(action, data));
}

std::unique_ptr<Server::Server> Create::Server()
{
	return std::make_unique<Server::Server>(Server::Server());
}

std::unique_ptr<Server::Server> Create::Server(std::unique_ptr<Communicators::Responder> responder)
{
	return std::make_unique<Server::Server>(Server::Server(std::move(responder)));
}

std::unique_ptr<Tamagotchi::Tamagotchi> Create::Tamagotchi()
{
	return std::make_unique<Tamagotchi::Tamagotchi>(Tamagotchi::Tamagotchi());
}

// MOCKS -------------------------------------------------------------------------------------------

std::unique_ptr<Mocks::ClientMock> CreateMocks::ClientMock()
{
	return std::make_unique<Mocks::ClientMock>();
}

std::unique_ptr<Mocks::ClientRequestMock> CreateMocks::ClientRequestMock()
{
	return std::make_unique<Mocks::ClientRequestMock>();
}

std::unique_ptr<Mocks::ServerResponseMock> CreateMocks::ServerResponseMock()
{
	return std::make_unique<Mocks::ServerResponseMock>();
}

std::unique_ptr<Mocks::StatusMock> CreateMocks::StatusMock()
{
	return std::make_unique<Mocks::StatusMock>();
}

std::unique_ptr<Mocks::RemoteResponderMock> CreateMocks::RemoteResponderMock()
{
	return std::make_unique<Mocks::RemoteResponderMock>();
}

std::unique_ptr<Mocks::ResponderMock> CreateMocks::ResponderMock()
{
	return std::make_unique<Mocks::ResponderMock>();
}

std::unique_ptr<Mocks::SenderMock> CreateMocks::SenderMock()
{
	return std::make_unique<Mocks::SenderMock>();
}

std::unique_ptr<Mocks::LogMock> CreateMocks::LogMock()
{
	return std::make_unique<Mocks::LogMock>();
}

std::unique_ptr<Mocks::ServerMock> CreateMocks::ServerMock()
{
	return std::make_unique<Mocks::ServerMock>();
}

std::unique_ptr<Mocks::TamagotchiMock> CreateMocks::TamagotchiMock()
{
	return std::make_unique<Mocks::TamagotchiMock>();
}
