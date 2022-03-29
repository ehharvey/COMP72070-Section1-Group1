#include "Communication.h"

Data::ClientRequest::ClientRequest()
	: __command_creator(Command::New)
{
	
}

Data::ClientRequest::ClientRequest(uint8_t authbyte, CommandAction command)
	: __command_creator(Command::New)
{
	
}

Data::ClientRequest::ClientRequest(const std::vector<uint8_t> Serialization)
	: __command_creator(Command::New)
{
	// First byte is authbyte
	
}

std::shared_ptr<Data::ISerializable> Data::ClientRequest::getAuthorization()
{
	return this->authorization;
}

// #StillAStub
std::shared_ptr<Data::ICommand> Data::ClientRequest::getCommand()
{
	return this->command;
}

const std::vector<uint8_t> Data::ClientRequest::Serialize()
{
	return SerializationGroup::New()
		->add(this->getAuthorization())
		->add(this->getCommand())
		->Serialize();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New()
{
	return std::unique_ptr<ClientRequest>();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(uint8_t authbyte, CommandAction command)
{
	return std::unique_ptr<ClientRequest>();
}

std::unique_ptr<Data::ClientRequest> Data::ClientRequest::New(const std::vector<uint8_t> Serialization)
{
	return std::unique_ptr<ClientRequest>();
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

std::shared_ptr<Data::IStatus> Data::ServerResponse::getTamagotchiStatus()
{
	return std::unique_ptr<IStatus>();
}

std::shared_ptr<Data::ISerializable> Data::ServerResponse::getAnimation()
{
	return std::unique_ptr<ISerializable>();
}

std::shared_ptr<Data::ISerializable> Data::ServerResponse::getResult()
{
	return std::shared_ptr<ISerializable>();
}

const std::vector<uint8_t> Data::ServerResponse::Serialize()
{
	return SerializationGroup::New()
		->add(this->getAnimation())
		->add(this->getResult())
		->add(this->getTamagotchiStatus())
		->Serialize();
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New()
{
	return std::unique_ptr<ServerResponse>();
}

std::unique_ptr<Data::ServerResponse> Data::ServerResponse::New(const std::vector<uint8_t> Serialization)
{
	return std::unique_ptr<ServerResponse>();
}

Data::Status::Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
{
	uint8_t happiness_and_alertness = (Happiness << 4) | (Alertness << 4 >> 4);
	uint8_t cleanliness_and_stomach = (Cleanliness << 4) | (StomachLevel << 4 >> 4);
	this->Payload = {happiness_and_alertness, cleanliness_and_stomach};
}

Data::Status::Status(const std::vector<uint8_t> Serialization)
{
	this->Payload = std::vector<uint8_t>{Serialization[0], Serialization[1]};	
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
	return this->Payload;
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

std::unique_ptr < Data::SerializationGroup > Data::SerializationGroup::New()
{
	return std::unique_ptr<SerializationGroup>();
}

Data::SerializationGroup::SerializationGroup(const std::vector<uint8_t> Serialization)
{
}

Data::SerializationGroup::SerializationGroup()
{
}

std::vector<Data::_packet>::iterator Data::SerializationGroup::begin()
{
	return std::vector<_packet>::iterator();
}

std::vector<Data::_packet>::iterator Data::SerializationGroup::end()
{
	return std::vector<_packet>::iterator();
}

std::unordered_map<std::type_index, std::vector<std::unique_ptr<Data::ISerializable>>> Data::SerializationGroup::get()
{
	return std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>>();
}

std::unique_ptr<Data::ISerializationGroup> Data::SerializationGroup::add(std::unique_ptr<ISerializable> item)
{
	return std::unique_ptr<ISerializationGroup>();
}

std::unique_ptr<Data::ISerializationGroup> Data::SerializationGroup::add(std::shared_ptr<ISerializable> item)
{
	return std::unique_ptr<ISerializationGroup>();
}

const std::vector<uint8_t> Data::SerializationGroup::Serialize()
{
	return std::vector<uint8_t>();
}

Data::Authorization::Authorization(std::vector<uint8_t> Serialization)
{
}

Data::Authorization::Authorization(uint8_t AuthByte)
{
}

uint8_t Data::Authorization::getAuthByte()
{
	return uint8_t();
}

const std::vector<uint8_t> Data::Authorization::Serialize()
{
	return std::vector<uint8_t>();
}

const std::vector<uint8_t> Data::Animation::Serialize()
{
	return std::vector<uint8_t>();
}
