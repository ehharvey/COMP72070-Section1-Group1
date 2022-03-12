#pragma once

#include <cstdint>
#include <vector>
#include "../Tamagotchi/Tamagotchi.h"
#include <optional>
#include <queue>
#include "gmock/gmock.h"

namespace Communication {
	// Interfaces -------------------------------------------------------------------
	__interface IData
	{
		const uint8_t* getPayload();
		size_t getSize();
	};

	__interface ICommunicator
	{
		void Initialize();
		void Send(IData&);
		IData& Receive();
		void Close();
	};

	__interface IClientRequest
	{
		uint8_t getAuthByte();
		Tamagotchi::Command getCommand();
	};

	class Animation;

	__interface IServerResponse
	{
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::Status> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
	};

	// ---------------------------------------------------------------
	// ---------------------------------------------------------------
	// ---------------------------------------------------------------

	class Data : public IData {
		uint8_t* payload;
		size_t size;

	public:
		Data(uint8_t * payload, size_t size);
		const uint8_t* getPayload();
		size_t getSize();
		~Data();
	};

	typedef struct ipv4_address {
		uint8_t octet[3];
	} IPV4Address;

	class ITcpCommunicator : public ICommunicator
	{
		IPV4Address local;
		std::vector<IPV4Address> remotes; // We can have 0 or more remotes

	public:
		ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes);

		void Initialize();
		void Send(Data);
		IData& Receive();
		void Close();

		void AddRemote(IPV4Address);
	};

	const int HELLO = 1;

	class ClientRequest : public IClientRequest {
	private:
		struct _Payload {
			uint8_t AuthByte;
			uint8_t CommandByte;
		} Payload;
	public:
		uint8_t getAuthByte();
		Tamagotchi::Command getCommand();
	};
	
	class Animation {
	private:
		std::queue<uint8_t> frames;
	};

	class ServerResponse : public IServerResponse {
	private:
		struct _Payload {
			uint8_t ResultByte;
			std::optional<Tamagotchi::Status> Status;
			std::optional<Animation> Animation;
		} Payload;
	public:
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::Status> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
	};

	class ITcpServer : ITcpCommunicator {
	public:
		/*
		void Initialize();
		void Send(Data);
		Data Receive();
		void Close();
		*/

		// Server-specific function
		void Await(); // Waits for and establishes a connection with a client
	};

	class ITcpClient : ITcpCommunicator {
	public:
		/*
		void Initialize();
		void Send(Data);
		Data Receive();
		void Close();
		*/

		// Client-specific function
		void ConnectTo(IPV4Address); // Connects to a server
	};

	// Idea: Implement local?
	// e.g., Client-Server communication uses interprocess communication
	class ILocalCommunicator : public ICommunicator
	{
	public:
		void Initialize();
		void Send( IData&);
		IData& Receive();
		void Close();
	};
}

namespace CommunicationMocks {
	class MockData : public Communication::IData {
	public:
		MOCK_METHOD(const uint8_t*, getPayload, ());
		// We can set this to return a specific value:
		// ON_CALL(obj_name, getData()).WillByDefault(Return("Hello World"));

		MOCK_METHOD(size_t, getSize, ());
	};

	class MockCommunicator : public Communication::ICommunicator {
		MOCK_METHOD(void, Initialize, ());
		MOCK_METHOD(void, Send, (Communication::IData&));
		MOCK_METHOD(Communication::IData&, Receive, ());
		MOCK_METHOD(void, Close, ());
	};

	class MockClientRequest : public Communication::IClientRequest {
		MOCK_METHOD(uint8_t, getAuthByte, ());
		MOCK_METHOD(Tamagotchi::Command, getCommand, ());
	};

	class MockServerRequest : public Communication::IServerResponse {
		MOCK_METHOD(bool, AuthSuccess, ());
		MOCK_METHOD(std::optional<Tamagotchi::Command>, getCurrentTamagotchiCommand, ());
		MOCK_METHOD(std::optional<Tamagotchi::Status>, getTamagotchiStatus, ());
		MOCK_METHOD(std::optional<Communication::Animation>, getAnimation, ());
	};
}