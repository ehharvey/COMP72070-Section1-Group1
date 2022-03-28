#include "Communication.h"

const Data::CommandParser DefaultCommandParser = [](uint8_t command_byte)
{
	return Data::Command::idle;
};

Data::ClientRequest::ClientRequest()
	: __command_parser(DefaultCommandParser)
{
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, Command command)
	: __command_parser(DefaultCommandParser)
{
	this->Payload.AuthByte = authbyte;
	this->Payload.CommandByte = command;
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
	: __command_parser(DefaultCommandParser)
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

void Data::ClientRequest::__setCommandParser(Data::CommandParser command_parser)
{
	this->__command_parser = command_parser;
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
	return std::optional<Data::Animation>();
}

const std::vector<uint8_t> Data::ServerResponse::Serialize()
{
	return std::vector<uint8_t>();
}

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	
}

Data::Status::Status(uint16_t Payload)
{

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
