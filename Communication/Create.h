#pragma once
#include <memory>
#include "Communication.h"

namespace Create
{
	// Data:: (from Communication.h)
	std::unique_ptr<Data::ClientRequest> ClientRequest()
	{
		return std::make_unique<Data::ClientRequest>(Data::ClientRequest());
	}
	std::unique_ptr<Data::ClientRequest> ClientRequest(const std::vector<uint8_t> Serialization)
	{
		return std::make_unique<Data::ClientRequest>(Data::ClientRequest(Serialization));
	}

	std::unique_ptr<Data::ServerResponse> ServerResponse()
	{
		return std::make_unique<Data::ServerResponse>(Data::ServerResponse());
	}
	std::unique_ptr<Data::ServerResponse> ServerResponse(const std::vector<uint8_t> Serialization)
	{
		return std::make_unique<Data::ServerResponse>(Data::ServerResponse(Serialization));
	}

	std::unique_ptr<Data::Status> Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
	{
		return std::make_unique<Data::Status>(Data::Status(Happiness, Alertness, Cleanliness, StomachLevel));
	}
	std::unique_ptr<Data::Status> Status(uint16_t Payload)
	{
		return std::make_unique<Data::Status>(Data::Status(Payload));
	}

	// Comunicators:: (from Communication.h)
	// To initialize:
	// - auto IP = Data::IPV4Address { 192, 168, 2, 100 }
	// - auto remote = Create::RemoteTcpServer(IP);
	// 
	//  (or)
	// 
	// - auto remote = Create::RemoteTcpServer({192, 168, 1, 100});
	std::unique_ptr<Communicators::RemoteTcpServer> RemoteTcpServer(Data::IPV4Address address)
	{
		return std::make_unique<Communicators::RemoteTcpServer>(Communicators::RemoteTcpServer(address));
	}
	std::unique_ptr<Communicators::TcpHost> TcpHost(Data::IPV4Address address, Communicators::rPtr response_function)
	{
		return std::make_unique<Communicators::TcpHost>(Communicators::TcpHost(address, response_function));
	}
	std::unique_ptr<Communicators::TcpClient> TcpClient(Data::IPV4Address address, std::unique_ptr<Communicators::RemoteResponder> remote)
	{
		return std::make_unique<Communicators::TcpClient>(Communicators::TcpClient(address, std::move(remote)));
	}
}

namespace CreateMocks
{
	namespace CreateMocks
	{
		// Data:: (from Communication.h)
		std::unique_ptr<Mocks::ClientRequestMock> ClientRequestMock()
		{
			return std::make_unique<Mocks::ClientRequestMock>();
		}
		std::unique_ptr<Mocks::ServerResponseMock> ServerResponseMock()
		{
			return std::make_unique<Mocks::ServerResponseMock>();
		}
		std::unique_ptr<Mocks::StatusMock> StatusMock()
		{
			return std::make_unique<Mocks::StatusMock>();
		}

		// Comunicators:: (from Communication.h)
		std::unique_ptr<Mocks::RemoteResponderMock> RemoteResponderMock()
		{
			return std::make_unique<Mocks::RemoteResponderMock>();
		}
		std::unique_ptr<Mocks::ResponderMock> ResponderMock()
		{
			return std::make_unique<Mocks::ResponderMock>();
		}
		std::unique_ptr<Mocks::SenderMock> SenderMock()
		{
			return std::make_unique<Mocks::SenderMock>();
		}
	}
}