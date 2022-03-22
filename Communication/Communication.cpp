#include "Communication.h"
#include <exception>


Communication::ITcpCommunicator::ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes)
{
	this->local = local;
	this->remotes = remotes;
}

void Communication::ITcpCommunicator::Initialize()
{
	return;
}

void Communication::ITcpCommunicator::Send(const std::vector<uint8_t>)
{
}

const std::vector<uint8_t> Communication::ITcpCommunicator::Receive()
{
	return std::vector<uint8_t>();
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

Communication::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
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

const std::vector<uint8_t> Communication::ClientRequest::Serialize()
{
	return std::vector<uint8_t>();
}




Communication::ServerResponse::ServerResponse()
{
}

Communication::ServerResponse::ServerResponse(const std::vector<uint8_t> Serialization)
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

const std::vector<uint8_t> Communication::ServerResponse::Serialize()
{
	return std::vector<uint8_t>();
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


const std::vector<uint8_t> Communication::ILocalCommunicator::Receive()
{
	return std::vector<uint8_t>();
}

void Communication::ILocalCommunicator::Close()
{
}
