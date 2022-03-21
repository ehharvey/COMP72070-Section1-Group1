

#include "Communication.h"
#include <exception>

Communication::Data::Data() 
{ 
	this->payload = std::nullptr_t(); 
	this->size = 0; 
}

Communication::Data::Data(std::unique_ptr<uint8_t> payload, size_t size)
{
}

std::unique_ptr<const uint8_t> Communication::Data::getPayload()
{
	return std::unique_ptr<const uint8_t>();
}

size_t Communication::Data::getSize()
{
	return size_t();
}

Communication::Data::~Data()
{
}

Communication::ITcpCommunicator::ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes)
{
}

void Communication::ITcpCommunicator::Initialize()
{
}

void Communication::ITcpCommunicator::Send(std::unique_ptr<IData>)
{
}

std::unique_ptr<Communication::IData> Communication::ITcpCommunicator::Receive()
{
	return std::unique_ptr<IData>();
}

void Communication::ITcpCommunicator::Close()
{
}

void Communication::ITcpCommunicator::AddRemote(IPV4Address)
{
}

Communication::ClientRequest::ClientRequest()
{
}

Communication::ClientRequest::ClientRequest(std::unique_ptr<IData> Serialization)
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

std::unique_ptr<Communication::IData> Communication::ClientRequest::Serialize()
{
	return std::unique_ptr<Communication::IData>();
}

Communication::ServerResponse::ServerResponse()
{
}

Communication::ServerResponse::ServerResponse(std::unique_ptr<IData> Serialization)
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

std::unique_ptr<Communication::IData> Communication::ServerResponse::Serialize()
{
	return std::unique_ptr<IData>();
}

void Communication::ITcpServer::Await()
{
}

void Communication::ITcpClient::ConnectTo(IPV4Address)
{
}

void Communication::ILocalCommunicator::Initialize()
{
}

void Communication::ILocalCommunicator::Send(std::unique_ptr<IData>)
{
}

std::unique_ptr<Communication::IData> Communication::ILocalCommunicator::Receive()
{
	return std::unique_ptr<IData>();
}

void Communication::ILocalCommunicator::Close()
{
}
