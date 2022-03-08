#pragma once

#include <cstdint>
#include <vector>

namespace Communication {
	const int HELLO = 1;

	class ClientRequest {
	private:
		struct data {
			uint8_t AuthByte;
			uint8_t CommandByte;
		} Data;
	public:

	};

	struct ServerResponse {
	private:
		struct data {
			uint8_t ResultByte;
			struct status {
				uint8_t Payload[2];
			} Status;
		} Data;
	public:

	};

	typedef struct ipv4_address {
		uint8_t octet[3]; 
	} IPV4Address;

	__interface ITCPNetworker
	{
		void Initialize();
		void ConnectTo();
		void Send();
		void Receive();
		void Close();
	};

	class IPSocket : ITCPNetworker
	{
		IPV4Address local;
		std::vector<IPV4Address> remotes; // We can have 0 or more remotes

	public:
		IPSocket(IPV4Address local);

		void Initialize();
		void ConnectTo();
		void Send();
		void Receive();
		void Close();
	};
}