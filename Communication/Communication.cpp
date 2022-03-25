#include "Communication.h"

Data::ClientRequest::ClientRequest()
{
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, Command command)
{
	this->Payload.AuthByte = authbyte;
	this->Payload.CommandByte = command;
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
{
}

uint8_t Data::ClientRequest::getAuthByte()
{
	return this->Payload.AuthByte;
}

// #StillAStub
Data::Command Data::ClientRequest::getCommand()
{
	return Data::Command::sleep;
}

const std::vector<uint8_t> Data::ClientRequest::Serialize()
{
	std::vector<uint8_t> serialization;
	serialization.push_back(this->Payload.AuthByte);
	serialization.push_back(this->Payload.CommandByte);
	return serialization;
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

const std::vector<uint8_t> Data::Status::Serialize()
{
	return std::vector<uint8_t>();
}

Communicators::rPtr Communicators::RemoteTcpServer::getSendFunction()
{
	return rPtr();
}

void Communicators::TcpHost::Start()
{
}

bool Communicators::TcpHost::getIsRunning()
{
	return false;
}

void Communicators::TcpHost::Stop()
{
}

void Communicators::TcpHost::RegisterResponse(Communicators::rPtr response_function)
{
}

const std::vector<uint8_t> Communicators::TcpClient::Send(const std::vector<uint8_t> message)
{
	return std::vector<uint8_t>();
}
