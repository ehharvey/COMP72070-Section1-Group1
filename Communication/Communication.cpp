#include "Communication.h"
#include <exception>

Communication::Data::Data(uint8_t * payload, size_t size) {
	this->payload = (uint8_t*)malloc(size);

	if (this->payload == NULL) {
		throw std::bad_alloc();
	}
	else {
		memcpy(this->payload, payload, size);
		this->size = size;
	}
}

const uint8_t* Communication::Data::getPayload()
{
	return this->payload;
}

size_t Communication::Data::getSize()
{
	return this->size;
}

Communication::Data::~Data() {
	if (this->payload != NULL) {
		free(this->payload);
	}
}

Communication::ITcpCommunicator::ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes)
{
	this->local = local;
	this->remotes = remotes;
}

void Communication::ITcpCommunicator::Initialize()
{
	return;
}

void Communication::ITcpCommunicator::Send(Data)
{
	return;
}

Communication::IData& Communication::ITcpCommunicator::Receive()
{
	Communication::Data result;
	return result;
}

void Communication::ITcpCommunicator::Close()
{
	return;
}

void Communication::ITcpCommunicator::AddRemote(IPV4Address)
{
	return;
}

Communication::ClientRequest::ClientRequest()
{
}

Communication::ClientRequest::ClientRequest(IData& Serialization)
{
}

uint8_t Communication::ClientRequest::getAuthByte()
{
	return uint8_t();
}

Tamagotchi::Command Communication::ClientRequest::getCommand()
{
	return Tamagotchi::Command();
}

Communication::IData& Communication::ClientRequest::Serialize()
{
	Communication::Data ret;
	return ret;
}


Communication::ServerResponse::ServerResponse()
{
}

Communication::ServerResponse::ServerResponse(IData& Serialization)
{
}

bool Communication::ServerResponse::AuthSuccess()
{
	return false;
}

std::optional<Tamagotchi::Command> Communication::ServerResponse::getCurrentTamagotchiCommand()
{
	return std::optional<Tamagotchi::Command>();
}

std::optional<Tamagotchi::Status> Communication::ServerResponse::getTamagotchiStatus()
{
	return std::optional<Tamagotchi::Status>();
}

std::optional<Communication::Animation> Communication::ServerResponse::getAnimation()
{
	return std::optional<Animation>();
}

Communication::IData& Communication::ServerResponse::Serialize()
{
	Communication::Data ret;
	return ret;
	// // O: insert return statement here
}

void Communication::ITcpServer::Await()
{
	return;
}

void Communication::ITcpClient::ConnectTo(IPV4Address)
{
	return;
}

void Communication::ILocalCommunicator::Initialize()
{
}

void Communication::ILocalCommunicator::Send(IData&)
{
}

Communication::IData& Communication::ILocalCommunicator::Receive()
{
	Communication::Data data;
	return data;
}

void Communication::ILocalCommunicator::Close()
{
}
