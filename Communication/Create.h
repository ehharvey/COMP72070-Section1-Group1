#pragma once
#include "IContainer.h"
#include <utility>
#include <memory>
#include "Animation.h"
#include "Authorization.h"
#include "ClientRequest.h"
#include "Command.h"
#include "CommandAction.h"
#include "CommandBuilder.h"
#include "ServerResponse.h"
#include "Status.h"
#include "RemoteTcpServer.h"
#include "TcpHost.h"
#include "TypeConstructor.h"
#include "SerializationGroup.h"
#include "Result.h"

namespace Data
{
	enum Stat
	{
		happiness,
		alertness,
		cleanliness,
		stomachlevel
	};
}

// Example usage:
// #include "../Communication/Create.h"
// 
// ...
// auto client_request = Create::ClientRequest();
namespace Create
{
	//
	std::unique_ptr<Data::ClientRequest> 
	ClientRequest
	(std::shared_ptr<Data::IAuthorization> authorization, std::shared_ptr<Data::ICommand> command);

	std::unique_ptr<Data::ClientRequest> 
	ClientRequest
	(Data::IContainer Serialization);

	std::unique_ptr<Data::ClientRequest>
		DeserializeClientRequest
		(Data::IContainer Serialization);;
	//
	//
	std::unique_ptr<Data::ServerResponse> 
	ServerResponse
	(Data::IContainer Serialization);

	std::unique_ptr<Data::ServerResponse>
	ServerResponse
	(std::unique_ptr<Data::IStatus> status, std::unique_ptr<Data::IAnimation> animation,
		std::unique_ptr<Data::IResult> result);
	//
	//
	std::unique_ptr<Data::Status> 
	Status
	(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);

	std::unique_ptr<Data::Status> 
	Status
	(Data::IContainer Serialization);
	//
	//
	std::unique_ptr<Data::Command> 
	Command
	(Data::IContainer Serialization);

	std::unique_ptr<Data::Command> 
	Command
	(Data::CommandAction action);



	// Comunicators:: (from Communication.h)
	// To initialize:
	// - auto IP = Data::IPV4Address { 192, 168, 2, 100 }
	// - auto remote = Create::RemoteTcpServer(IP);
	// 
	//  (or)
	// 
	// - auto remote = Create::RemoteTcpServer({192, 168, 1, 100});
	std::unique_ptr<Communicators::RemoteTcpServer> RemoteTcpServer(Data::IPV4Address address);
	std::unique_ptr<Communicators::TcpHost> TcpHost(Communicators::rPtr response_function);

	// This should be moved eventually
	const auto client_type_constructor = 
		std::make_pair<std::type_index, Data::ISerializableConstructor>
		(std::type_index(typeid(Data::ClientRequest)), Create::DeserializeClientRequest);

	const std::vector<std::pair<std::type_index, Data::ISerializableConstructor>> deserializers
		= { Data::authorization_type_constructor,
			Data::command_type_pair,
			Data::animation_type_constructor,
			client_type_constructor,
			Data::status_type_constructor,
			Data::result_type_constructor
			};

	const auto serializationGroupConstructors = []()
	{
		return Data::SerializationGroup::New(std::make_shared<Data::TypeConstructor>(deserializers));
	};
}