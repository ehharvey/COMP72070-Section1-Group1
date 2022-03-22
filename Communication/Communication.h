#pragma once

#include <cstdint>
#include <vector>
#include "../Tamagotchi/Tamagotchi.h"
#include <optional>
#include <queue>
#include "gmock/gmock.h"

namespace Communication {
	// Interfaces -------------------------------------------------------------------
	__interface ISerializable
	{
		const std::vector<uint8_t> Serialize();
	};

	__interface ICommunicator
	{
		void Initialize();
		void Send(const std::vector<uint8_t>);
		const std::vector<uint8_t> Receive();
		void Close();
	};

	__interface IClientRequest : public ISerializable
	{
		uint8_t getAuthByte();
		Tamagotchi::Command getCommand();
	};

	class Animation;

	__interface IServerResponse : public ISerializable
	{
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::Status> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
	};

	// ---------------------------------------------------------------
	// ---------------------------------------------------------------
	// ---------------------------------------------------------------

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
		void Send(const std::vector<uint8_t>);
		const std::vector<uint8_t> Receive();
		void Close();

		void AddRemote(IPV4Address);
	};

	class ClientRequest : public IClientRequest {
	private:
		struct _Payload {
			uint8_t AuthByte;
			uint8_t CommandByte;
		} Payload;
	public:
		ClientRequest();
		ClientRequest(const std::vector<uint8_t> Serialization);
		uint8_t getAuthByte();
		Tamagotchi::Command getCommand();
		const std::vector<uint8_t> Serialize();
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
		ServerResponse();
		ServerResponse(const std::vector<uint8_t> Serialization);
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::Status> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
		const std::vector<uint8_t> Serialize();
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
		void Send(const std::vector<uint8_t>);
		const std::vector<uint8_t> Receive();
		void Close();
	};
}

namespace CommunicationMocks {
	class MockCommunicator : public Communication::ICommunicator {
		MOCK_METHOD(void, Initialize, ());
		MOCK_METHOD(void, Send, (const std::vector<uint8_t>));
		MOCK_METHOD(const std::vector<uint8_t>, Receive, ());
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