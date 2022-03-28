#pragma once
#include <memory>
#include "Communication.h"

// Example usage:
// #include "../Communication/Create.h"
// 
// ...
// auto client_request = Create::ClientRequest();
namespace Create
{
	// Data:: (from Communication.h)
	std::unique_ptr<Data::ClientRequest> ClientRequest();
	std::unique_ptr<Data::ClientRequest> ClientRequest(uint8_t authbyte, Data::Command command);
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
	std::unique_ptr<Communicators::TcpClient> TcpClient(Data::IPV4Address address, std::unique_ptr<Communicators::IRemoteResponder> remote);
}