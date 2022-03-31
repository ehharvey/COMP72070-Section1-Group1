#pragma once
#include "../../Client/Client.h"
#include "Communication.h"
#include "../../Logger/Logger.h"
#include "../../Server/Server.h"
#include "../../Tamagotchi/Tamagotchi.h"
#include <gmock/gmock.h>

// Client
namespace Mocks {
	class ClientMock : public Client::IClient {
	public:
		MOCK_METHOD(std::unique_ptr<Data::IServerResponse>, SendCommand, (std::unique_ptr<Data::IClientRequest>));
	};

	class LogMock : public Logger::ILog {
	public:
		MOCK_METHOD(time_t, getTime, ());
		MOCK_METHOD(Data::IContainer, getData, ());
		MOCK_METHOD(Logger::action, getAction, ());
	};

	// Server
	// As Server is itself a Communicators::Responder, we can mock it 
	// via Mocks::ResponderMock
	typedef Mocks::ResponderMock ServerMock;

	class TamagotchiMock : public Tamagotchi::ITamagotchi {
	public:
		MOCK_METHOD(void, AddCommand, (Data::CommandAction));
		MOCK_METHOD(void, AddCommand_Immediate, (Data::CommandAction));
		MOCK_METHOD(Data::CommandAction, GetCurrentCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getStatus, ());
		MOCK_METHOD(void, adjustStat, (Data::Stat, signed int relativeChange));
	};
}

namespace CreateMocks
{
	std::unique_ptr<Mocks::LogMock> LogMock()
	{
		return std::make_unique<Mocks::LogMock>();
	}

	// Server:: (from Server.h)
	std::unique_ptr<Mocks::ServerMock> ServerMock()
	{
		return std::make_unique<Mocks::ServerMock>();
	}

	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Mocks::TamagotchiMock> TamagotchiMock()
	{
		return std::make_unique<Mocks::TamagotchiMock>();
	}
}