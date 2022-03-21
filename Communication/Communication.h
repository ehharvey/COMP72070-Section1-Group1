#pragma once
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <cstdint>
#include <vector>
#include "../Tamagotchi/Tamagotchi.h"
#include <optional>
#include <queue>
#include <memory>
#include "gmock/gmock.h"

namespace Communication {
	// Interfaces -------------------------------------------------------------------
	__interface IData
	{
		std::unique_ptr<const uint8_t> getPayload();
		size_t getSize();
	};

	__interface ISerializable
	{
		std::unique_ptr<IData> Serialize();
	};

	__interface ICommunicator
	{
		void Initialize();
		void Send(std::unique_ptr<IData>);
		std::unique_ptr<IData> Receive();
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

	class Data : public IData {
		std::unique_ptr<uint8_t> payload;
		size_t size;

	public:
		Data();
		Data(std::unique_ptr<uint8_t> payload, size_t size);
		std::unique_ptr<const uint8_t> getPayload();
		size_t getSize();
		~Data();
	};

	typedef struct ipv4_address {
		uint8_t octet[3];
	} IPV4Address;

	class ITcpCommunicator : public ICommunicator
	{
		SOCKET connection_socket;
		IPV4Address local;
		std::vector<IPV4Address> remotes; // We can have 0 or more remotes

	public:
		ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes);

		void Initialize();
		void Send(std::unique_ptr<IData>);
		std::unique_ptr<IData> Receive();
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
		ClientRequest(std::unique_ptr<IData> Serialization);
		uint8_t getAuthByte();
		Tamagotchi::Command getCommand();
		std::unique_ptr<IData> Serialize();
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
		ServerResponse(std::unique_ptr<IData> Serialization);
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::Status> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
		std::unique_ptr<IData> Serialize();
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
		void Send(std::unique_ptr<IData>);
		std::unique_ptr<IData> Receive();
		void Close();
	};
}

namespace CommunicationMocks {
	class MockData : public Communication::IData {
	public:
		MOCK_METHOD(std::unique_ptr<const uint8_t>, getPayload, ());
		// We can set this to return a specific value:
		// ON_CALL(obj_name, getData()).WillByDefault(Return("Hello World"));

		MOCK_METHOD(size_t, getSize, ());
	};

	class MockCommunicator : public Communication::ICommunicator {
		MOCK_METHOD(void, Initialize, ());
		MOCK_METHOD(void, Send, (Communication::IData&));
		MOCK_METHOD(std::unique_ptr<Communication::IData>, Receive, ());
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