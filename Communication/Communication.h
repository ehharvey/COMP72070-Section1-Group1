#pragma once

#include <cstdint>
#include <vector>
#include <optional>
#include <queue>
#include <future>
#include "gmock/gmock.h"

namespace Data {
	// Interfaces -------------------------------------------------------------------
	__interface ISerializable
	{
		const std::vector<uint8_t> Serialize();
	};

	__interface IStatus
	{
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getCleaniness();
		void setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
	};

	enum Command
	{
		feed,
		sleep,
		clean,
		idle
	};

	enum Stat {
		alertness, stomach, cleanliness, happiness
	};
	
	__interface IClientRequest : public ISerializable
	{
		uint8_t getAuthByte();
		Command getCommand();
	};

	class Animation;
	__interface IServerResponse : public ISerializable
	{
		bool AuthSuccess();
		std::optional<Command> getCurrentTamagotchiCommand();
		std::unique_ptr<IStatus> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
	};

	//-------------------------------------------------------------------------------


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
		Command getCommand();
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
			
			std::optional<Animation> Animation;
		} Payload;
	public:
		ServerResponse();
		ServerResponse(const std::vector<uint8_t> Serialization);
		bool AuthSuccess();
		std::optional<Command> getCurrentTamagotchiCommand();
		std::unique_ptr<IStatus> getTamagotchiStatus();
		std::optional<Animation> getAnimation();
		const std::vector<uint8_t> Serialize();
	};

	class Status : public IStatus {
		// Payload format
		// hhhh aaaa [happiness alertness]
		// ssss cccc [stomach cleaniness]
		uint16_t Payload; // 2 bytes
	public:
		uint8_t getHappiness() { return Payload >> 12; };
		uint8_t getAlertness() { return Payload << 4 >> 12; };
		uint8_t getStomachLevel() { return Payload << 8 >> 12; };
		uint8_t getCleaniness() { return Payload << 12 >> 12; };

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);
		void setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
	};
}

namespace DataMocks {
	class MockClientRequest : public Data::IClientRequest {
		MOCK_METHOD(uint8_t, getAuthByte, ());
		MOCK_METHOD(Data::Command, getCommand, ());
	};

	class MockServerRequest : public Data::IServerResponse {
		MOCK_METHOD(bool, AuthSuccess, ());
		MOCK_METHOD(std::optional<Data::Command>, getCurrentTamagotchiCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getTamagotchiStatus, ());
		MOCK_METHOD(std::optional<Data::Animation>, getAnimation, ());
	};

	class MockStatus : public Data::Status {
		MOCK_METHOD(uint8_t, getHappiness, ());
		MOCK_METHOD(uint8_t, getAlertness, ());
		MOCK_METHOD(uint8_t, getStomachLevel, ());
		MOCK_METHOD(uint8_t, getDirtiness, ());
	};
}

namespace Communicators
{
	typedef const std::vector<uint8_t>(*rPtr)(const std::vector<uint8_t>);
	__interface RemoteResponder
	{
		// To use:
		// {
		//		auto remote_responder = Create::MockRemoteResponder();
		//		auto send_function = remote_responder.getSendFunction();
		//
		//		std::vector<uint8_t> payload = { 'h', 'e', 'l', 'l', 'o' };
		//		auto server_response = send_function(payload);
		// }
		rPtr getSendFunction();
	};

	__interface Sender
	{
		const std::vector<uint8_t> Send(const std::vector<uint8_t> message); // Returns the received response
	};

	__interface Responder
	{
		// This function does not return anything. It receives a pointer to another function as a parameter (you can use lambda instead)
		//
		// The lambda should do a few things:
		// - It should take in a std::vector<uint8_t>		<-- This will be the data that the client sent to the server as a [request]
		// - It should return a std::vector<uint8_t>		<-- This will be the data that will sent *back* to the client as a [response]
		void RegisterResponse(rPtr);

		void Start();
		void Stop();
		bool getIsRunning();
	};

	typedef struct ipv4_address {
		uint8_t octet[4];
	} IPV4Address;

	// This class is used by clients in order to connect to remote TCP servers
	class RemoteTcpServer : public RemoteResponder
	{
	private:
		IPV4Address address;

	public:
		RemoteTcpServer(IPV4Address address) :
			address(address)
		{ };

		// Returns a function that you can use to connect to this server
		rPtr getSendFunction();
	};

	// This class is used by server apps in order to start their own TCP server
	class TCPHost : public Responder
	{
	private:
		IPV4Address address;
		rPtr response_function;
	public:
		TCPHost(IPV4Address address, rPtr response_function) :
			address(address),
			response_function(response_function)
		{ };

		void Start();
		bool getIsRunning();
		void Stop();

	};

	class TCPClient : public Sender
	{
		IPV4Address address;
		std::unique_ptr<RemoteResponder> remote;

	public:
		TCPClient(IPV4Address address, std::unique_ptr<RemoteResponder> remote) :
			address(address),
			remote(std::move(remote))
		{ }

		const std::vector<uint8_t> Send(const std::vector<uint8_t> message);
	};
}

namespace CommunicatorsMocks
{
	class MockRemoteResponder : public Communicators::RemoteResponder
	{
		MOCK_METHOD(Communicators::rPtr, getSendFunction, ());
	};

	class MockSender : public Communicators::Sender
	{
		MOCK_METHOD(const std::vector<uint8_t>, Send, (const std::vector<uint8_t>));
	};

	class Responder : public Communicators::Responder
	{
		MOCK_METHOD(void, Start, ());
		MOCK_METHOD(bool, getIsRunning, ());
		MOCK_METHOD(void, Stop, ());
	};
}