#include "Communication.h"

Data::ClientRequest::ClientRequest()
	: __command_creator(Command::New)
{
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, CommandAction command)
	: __command_creator(Command::New)
{
	this->Payload.AuthByte = authbyte;
	this->Payload.CommandByte = command;
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
	: __command_creator(Command::New)
{
}

uint8_t Data::ClientRequest::getAuthByte()
{
	return this->Payload.AuthByte;
}

// #StillAStub
Data::CommandAction Data::ClientRequest::getCommand()
{
	return Data::CommandAction::sleep;
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

std::optional<Data::CommandAction> Data::ServerResponse::getCurrentTamagotchiCommand()
{
	return std::optional<Data::CommandAction>();
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

Data::Command::Command()
{
}

Data::Command::Command(const std::vector<uint8_t> Serialization)
{
}

Data::Command::Command(CommandAction action)
{
}

const std::vector<uint8_t> Data::Command::Serialize()
{
	return std::vector<uint8_t>();
}

Data::CommandAction Data::Command::getAction()
{
	return CommandAction();
}

std::unique_ptr<Data::Command> Data::Command::New(const std::vector<uint8_t> Serialization)
{
	return std::make_unique<Command>();
}
