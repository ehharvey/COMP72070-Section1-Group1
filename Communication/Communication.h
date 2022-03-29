#pragma once

#include <cstdint>
#include <vector>
#include <optional>
#include <queue>
#include <future>
#include <typeinfo>
#include <typeindex>

namespace Data {
	typedef struct ipv4_address {
		uint8_t octet[4];
	} IPV4Address;

	// Interfaces -------------------------------------------------------------------
	__interface ISerializable
	{
		const std::vector<uint8_t> Serialize();
	};

	struct _packet
	{
		struct header
		{
			std::type_info type;
		};
		std::unique_ptr<ISerializable> item;
	};

	__interface ISerializationGroup : public ISerializable
	{
		std::vector<_packet>::iterator begin();
		std::vector<_packet>::iterator end();

		// Returns a map *items*
		// items[typeid(ClientRequest)] retrieves all ClientRequest objects contained
		std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>> get();

		std::unique_ptr<ISerializationGroup> add(std::unique_ptr<ISerializable> item);
		std::unique_ptr<ISerializationGroup> add(std::shared_ptr<ISerializable> item);
	};

	__interface IStatus : public ISerializable
	{
		uint8_t getHappiness();
		uint8_t getAlertness();
		uint8_t getStomachLevel();
		uint8_t getCleaniness();
	};

	enum CommandAction
	{
		feed,
		sleep,
		clean,
		idle
	};

	__interface ICommand : public ISerializable
	{
		CommandAction getAction();
	};

	enum Stat {
		alertness, stomach, cleanliness, happiness
	};
	
	__interface IClientRequest : public ISerializable
	{
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();
	};

	class Animation;
	__interface IServerResponse : public ISerializable
	{
		bool AuthSuccess();
		std::shared_ptr<IStatus> getTamagotchiStatus();
		std::shared_ptr<ISerializable> getAnimation();
		std::shared_ptr<ISerializable> getResult();
	};

	__interface IAuthorization : public ISerializable
	{
		uint8_t getAuthByte();
	};

	//-------------------------------------------------------------------------------
	typedef std::function<std::unique_ptr<ICommand>(const std::vector<uint8_t> Serialization)> CommandCreator;

	
	class SerializationGroup : public ISerializationGroup
	{
	private:
		std::vector<_packet> items;
	public:
		SerializationGroup(const std::vector<uint8_t> Serialization);
		SerializationGroup();

		std::vector<_packet>::iterator begin();
		std::vector<_packet>::iterator end();

		// Returns a map *items*
		// items[typeid(ClientRequest)] retrieves all ClientRequest objects contained
		std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISerializable>>> get();
		
		std::unique_ptr<ISerializationGroup> add(std::unique_ptr<ISerializable> item);
		std::unique_ptr<ISerializationGroup> add(std::shared_ptr<ISerializable> item);
		const std::vector<uint8_t> Serialize();

		static std::unique_ptr<SerializationGroup> New();
	};

	class Command : public ICommand
	{
	private:
		CommandAction command_action;
	public:
		Command();
		Command(const std::vector<uint8_t> Serialization);
		Command(CommandAction action);

		const std::vector<uint8_t> Serialize();
		CommandAction getAction();
		
		static std::unique_ptr<Command> New(const std::vector<uint8_t> Serialization);
	};

	class Authorization : public IAuthorization
	{
	public:
		Authorization(std::vector<uint8_t> Serialization);
		Authorization(uint8_t AuthByte);
		uint8_t getAuthByte();
		const std::vector<uint8_t> Serialize();
	};

	
	class ClientRequest : public IClientRequest {
	private:
		CommandCreator __command_creator;
		std::shared_ptr<IAuthorization> authorization;
		std::shared_ptr<ICommand> command;
		
	public:
		ClientRequest();
		ClientRequest(uint8_t authbyte, CommandAction command);
		ClientRequest(const std::vector<uint8_t> Serialization);
		
		std::shared_ptr<ISerializable> getAuthorization();
		std::shared_ptr<ICommand> getCommand();

		const std::vector<uint8_t> Serialize();


		// Use these "constructors"
		static std::unique_ptr<ClientRequest> New();
		static std::unique_ptr<ClientRequest> New(uint8_t authbyte, CommandAction command);
		static std::unique_ptr<ClientRequest> New(const std::vector<uint8_t> Serialization);
	};
	
	class Animation : public ISerializable {
	private:
		std::queue<uint8_t> frames;

		const std::vector<uint8_t> Serialize();
	};

	class Result : public ISerializable {

	};

	class ServerResponse : public IServerResponse {
	private:
		std::shared_ptr<IStatus> status;
		std::shared_ptr<Animation> animation;
	public:
		// "Traditional" constructors: do not use!
		ServerResponse();
		ServerResponse(const std::vector<uint8_t> Serialization);
		
		bool AuthSuccess();
		std::optional<CommandAction> getCurrentTamagotchiCommand();
		std::shared_ptr<IStatus> getTamagotchiStatus();
		std::shared_ptr<ISerializable> getAnimation();
		std::shared_ptr<ISerializable> getResult();
		const std::vector<uint8_t> Serialize();

		// Our "constructors"
		static std::unique_ptr<ServerResponse> New();
		static std::unique_ptr<ServerResponse> New(const std::vector<uint8_t> Serialization);
	};

	class Status : public IStatus, public ISerializable {
		// Payload format
		// hhhh aaaa [happiness alertness]
		// ssss cccc [stomach cleaniness]
		std::vector<uint8_t> Payload; // 2 bytes
	public:
		Status(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		Status(const std::vector<uint8_t> Serialization);

		uint8_t getHappiness() { return Payload[0] >> 4; };
		uint8_t getAlertness() { return Payload[0] << 4 >> 4; };
		uint8_t getStomachLevel() { return Payload[1] >> 4; };
		uint8_t getCleaniness() { return Payload[1] << 4 >> 4; };

		void setHappiness(uint8_t happiness);
		void setAlertness(uint8_t alertness);
		void setStomachLevel(uint8_t stomach);
		void setCleaniness(uint8_t cleaniness);

		const std::vector<uint8_t> Serialize();

		// Our "constructors"
		static std::unique_ptr<Status> New(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel);
		static std::unique_ptr<Status> New(uint16_t Payload);
		static std::unique_ptr<Status> New(const std::vector<uint8_t> Serialization);
	};
}

namespace Communicators
{

	// rPtr: a lambda function indicating the response to an input
	// - Needs to be a function that receives a std::vector<uint8_t>	<---- (the request)
	// - This function needs to also return a std::vector<uint8_t>		<---- (the response)
	typedef std::function<std::vector<uint8_t>(std::vector<uint8_t>)> rPtr;

	

	__interface IRemoteResponder
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

	__interface ISender
	{
		const std::vector<uint8_t> Send(const std::vector<uint8_t> message); // Returns the received response
	};

	__interface IResponder
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

	// This class is used by clients in order to connect to remote TCP servers
	class RemoteTcpServer : public IRemoteResponder
	{
	private:
		Data::IPV4Address address;

	public:
		RemoteTcpServer(Data::IPV4Address address) :
			address(address)
		{ };

		// Returns a function that you can use to connect to this server
		rPtr getSendFunction();
	};

	// This class is used by server apps in order to start their own TCP server
	class TcpHost : public IResponder
	{
	private:
		Data::IPV4Address address;
		rPtr response_function;
	public:
		TcpHost(Data::IPV4Address address, rPtr response_function) :
			address(address),
			response_function(response_function)
		{ };

		void Start();
		bool getIsRunning();
		void Stop();
		void RegisterResponse(rPtr response_function);

	};

	class TcpClient : public ISender
	{
		Data::IPV4Address address;
		std::unique_ptr<IRemoteResponder> remote;

	public:
		TcpClient(Data::IPV4Address address, std::unique_ptr<IRemoteResponder> remote) :
			address(address),
			remote(std::move(remote))
		{ }

		const std::vector<uint8_t> Send(const std::vector<uint8_t> message);
	};
}