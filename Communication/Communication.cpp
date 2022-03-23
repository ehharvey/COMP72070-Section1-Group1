#include "Communication.h"

Data::ClientRequest::ClientRequest()
{
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
{
}

uint8_t Data::ClientRequest::getAuthByte()
{
	return uint8_t();
}

Data::Command Data::ClientRequest::getCommand()
{
	return Data::Command();
}

const std::vector<uint8_t> Data::ClientRequest::Serialize()
{
	return std::vector<uint8_t>();
}

Data::ServerResponse::ServerResponse()
{
}

Data::ServerResponse::ServerResponse(const std::vector<uint8_t> Serialization)
{
}

bool Data::ServerResponse::AuthSuccess()
{
	return false;
}

std::optional<Data::Command> Data::ServerResponse::getCurrentTamagotchiCommand()
{
	return std::optional<Data::Command>();
}

std::unique_ptr<Data::IStatus> Data::ServerResponse::getTamagotchiStatus()
{
	return std::unique_ptr<IStatus>();
}

std::optional<Data::Animation> Data::ServerResponse::getAnimation()
{
	return std::optional<Animation>();
}

const std::vector<uint8_t> Data::ServerResponse::Serialize()
{
	return std::vector<uint8_t>();
}

void Data::Status::setHappiness(uint8_t happiness)
{
}

void Data::Status::setAlertness(uint8_t alertness)
{
}

void Data::Status::setStomachLevel(uint8_t stomach)
{
}

void Data::Status::setCleaniness(uint8_t cleaniness)
{
}

void Data::Status::setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
}

Communicators::rPtr Communicators::RemoteTcpServer::getSendFunction()
{
	return rPtr();
}

void Communicators::TCPHost::Start()
{
}

bool Communicators::TCPHost::getIsRunning()
{
	return false;
}

void Communicators::TCPHost::Stop()
{
}

const std::vector<uint8_t> Communicators::TCPClient::Send(const std::vector<uint8_t> message)
{
	return std::vector<uint8_t>();
}
