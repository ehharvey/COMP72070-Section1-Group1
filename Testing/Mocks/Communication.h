#pragma once
#include <gmock/gmock.h>
#include "../../Communication/Create.h"

#define GRANT_NEW(Type) static std::unique_ptr<Type> New() { return std::make_unique<Type>(); }

namespace Mocks
{
    class ClientRequestMock : public Data::IClientRequest {
	public:
		MOCK_METHOD(std::shared_ptr<Data::ISerializable>, getAuthorization, ());
		MOCK_METHOD(std::shared_ptr<Data::ICommand>, getCommand, ());
		MOCK_METHOD(Data::IContainer, Serialize, ());

        GRANT_NEW(ClientRequestMock);
	};

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

	class SenderMock : public Communicators::ISender
	{
	public:
		MOCK_METHOD(Data::IContainer, Send, (Data::IContainer));

        GRANT_NEW(SenderMock);
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
}