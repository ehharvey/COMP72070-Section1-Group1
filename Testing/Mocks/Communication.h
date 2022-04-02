#pragma once
#include <gmock/gmock.h>
#include "../../Communication/Create.h"


#define GRANT_NEW(Type) static std::unique_ptr<Type> New() { return std::make_unique<Type>(); }

namespace Mocks
{
	class Serializable : public Data::ISerializable
	{
	public:
		MOCK_METHOD(Data::IContainer, Serialize, ());
		GRANT_NEW(Serializable);
	};

	class Authorization : public Data::IAuthorization
	{
	public:
		MOCK_METHOD(uint8_t, getAuthByte, ());

		GRANT_NEW(Authorization);
	};

    class ClientRequest : public Data::IClientRequest {
	public:
		MOCK_METHOD(Data::IAuthorization&, getAuthorization, ());
		MOCK_METHOD(Data::ICommand&, getCommand, ());
		MOCK_METHOD(Data::IContainer, Serialize, ());

        GRANT_NEW(ClientRequest);
	};

	class Command : public Data::ICommand
	{
	public:
		MOCK_METHOD(Data::IContainer, Serialize, ());
		MOCK_METHOD(Data::CommandAction, getAction, ());
	};

	class SerializationGroup : public Data::ISerializationGroup
	{
		
	}

	class ServerResponseMock : public Data::IServerResponse {
	public:
		MOCK_METHOD(bool, AuthSuccess, ());
		MOCK_METHOD(std::shared_ptr<Data::IStatus>, getTamagotchiStatus, ());
		MOCK_METHOD(std::shared_ptr<Data::ISerializable>, getAnimation, ());
		MOCK_METHOD(std::shared_ptr<Data::ISerializable>, getResult, ());
		MOCK_METHOD(Data::IContainer, Serialize, ());

        GRANT_NEW(ServerResponseMock);
	};

	class StatusMock : public Data::IStatus, public Data::ISerializable {
	public:
		MOCK_METHOD(uint8_t, getHappiness, ());
		MOCK_METHOD(uint8_t, getAlertness, ());
		MOCK_METHOD(uint8_t, getStomachLevel, ());
		MOCK_METHOD(uint8_t, getCleaniness, ());
		MOCK_METHOD(Data::IContainer, Serialize, ());
        
        GRANT_NEW(StatusMock);
	};

	class CommandMock : public Data::ICommand
	{
	public:
		MOCK_METHOD(Data::IContainer, Serialize,());
		MOCK_METHOD(Data::CommandAction, getAction,());

		GRANT_NEW(CommandMock);
		static std::unique_ptr<CommandMock> New(Data::IContainer Serialization);
	};

	class RemoteResponderMock : public Communicators::IRemoteResponder
	{
	public:
		MOCK_METHOD(Communicators::rPtr, getSendFunction, ());

        GRANT_NEW(RemoteResponderMock);
	};

	class ResponderMock : public Communicators::IResponder
	{
	public:
		MOCK_METHOD(void, Start, ());
		MOCK_METHOD(bool, getIsRunning, ());
		MOCK_METHOD(void, Stop, ());
		MOCK_METHOD(void, RegisterResponse, (Communicators::rPtr));

        GRANT_NEW(ResponderMock);
	};
} // namespace Mocks
