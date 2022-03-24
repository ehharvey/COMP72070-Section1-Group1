#pragma once

#include "../Client/Client.h"
#include "../Communication/Communication.h"
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
}