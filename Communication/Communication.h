#pragma once

#include <cstdint>
#include <vector>
#include "../Tamagotchi/Tamagotchi.h"
#include <optional>
#include <queue>

namespace Communication {
	// --------------------------------------------------------------------------------
	class Data {
		uint8_t* payload;
		size_t size;

	public:
		Data(uint8_t* payload, size_t size);
		const uint8_t* getPayload();
	};

	typedef struct ipv4_address {
		uint8_t octet[3];
	} IPV4Address;

	__interface ICommunicator
	{
		void Initialize();
		void Send(Data);
		Data Receive();
		void Close();
	};

	class ITcpCommunicator : public ICommunicator
	{
		IPV4Address local;
		std::vector<IPV4Address> remotes; // We can have 0 or more remotes

	public:
		ITcpCommunicator(IPV4Address local, std::vector<IPV4Address> remotes);

		void Initialize();
		void Send(Data);
		// Send_Async()? Might be needed for GUI or multiple tamagotchis
		Data Receive();
		// Receive_Async()? Might be needed for GUI or multiple tamagotchis
		void Close();

		void AddRemote(IPV4Address);
	};
	// -----------------------------------------------------------------------------

	const int HELLO = 1;

	class ClientRequest {
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

	class ServerResponse {
	private:
		struct _Payload {
			uint8_t ResultByte;
			std::optional<Tamagotchi::TamagotchiStatus> Status;
			std::optional<Animation> Animation;
		} Payload;
	public:
		bool AuthSuccess();
		std::optional<Tamagotchi::Command> getCurrentTamagotchiCommand();
		std::optional<Tamagotchi::TamagotchiStatus> getTamagotchiStatus();
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
		void Send(Data);
		Data Receive();
		void Close();
	};
}