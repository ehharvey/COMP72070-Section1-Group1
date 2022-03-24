#pragma once

#include "../Client/Client.h"
#include "../Communication/Communication.h"
#include "../Logger/Logger.h"
#include "../Server/Server.h"
#include "../Tamagotchi/Tamagotchi.h"
#include <memory>

namespace Create
{
	// Client (from Client.h)
	std::unique_ptr<Client::Client> Client();
	std::unique_ptr<Client::Client> Client(std::unique_ptr<Communicators::Sender> sender);


	// Data:: (from Communication.h)
	std::unique_ptr<Data::ClientRequest> ClientRequest();
	std::unique_ptr<Data::ClientRequest> ClientRequest(const std::vector<uint8_t> Serialization);

	std::unique_ptr<Data::ServerResponse> ServerResponse();
	std::unique_ptr<Data::ServerResponse> ServerResponse(const std::vector<uint8_t> Serialization);

	std::unique_ptr<Data::Status> Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
	std::unique_ptr<Data::Status> Status(uint16_t Payload);

	// Comunicators:: (from Communication.h)
	// To initialize:
	// - auto IP = Data::IPV4Address { 192, 168, 2, 100 }
	// - auto remote = Create::RemoteTcpServer(IP);
	// 
	//  (or)
	// 
	// - auto remote = Create::RemoteTcpServer({192, 168, 1, 100});
	std::unique_ptr<Communicators::RemoteTcpServer> RemoteTcpServer(Data::IPV4Address address);
	std::unique_ptr<Communicators::TcpHost> TcpHost(Data::IPV4Address address, Communicators::rPtr response_function);
	std::unique_ptr<Communicators::TcpClient> TcpClient(Data::IPV4Address address, std::unique_ptr<Communicators::RemoteResponder> remote);

	// Logger:: (from Logger.h)
	std::unique_ptr<Logger::Log> Log(Logger::action, const std::vector<uint8_t> data);

	// Server:: (from Server.h)
	std::unique_ptr<Server::Server> Server();
	std::unique_ptr<Server::Server> Server(std::unique_ptr<Communicators::Responder> responder);

	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Tamagotchi::Tamagotchi> Tamagotchi();
}

namespace CreateMocks
{
	// Client (from Client.h)
	std::unique_ptr<Mocks::ClientMock> ClientMock();


	// Data:: (from Communication.h)
	std::unique_ptr<Mocks::ClientRequestMock> ClientRequestMock();
	std::unique_ptr<Mocks::ServerResponseMock> ServerResponseMock();
	std::unique_ptr<Mocks::StatusMock> StatusMock();

	// Comunicators:: (from Communication.h)
	std::unique_ptr<Mocks::RemoteResponderMock> RemoteResponderMock();
	std::unique_ptr<Mocks::ResponderMock> ResponderMock();
	std::unique_ptr<Mocks::SenderMock> SenderMock();

	// Logger:: (from Logger.h)
	std::unique_ptr<Mocks::LogMock> LogMock();

	// Server:: (from Server.h)
	std::unique_ptr<Mocks::ServerMock> ServerMock();

	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Mocks::TamagotchiMock> TamagotchiMock();
}