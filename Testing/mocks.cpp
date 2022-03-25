// Client
namespace Mocks {
	class ClientMock : public Client::IClient {
	public:
		MOCK_METHOD(std::unique_ptr<Data::IServerResponse>, SendCommand, (std::unique_ptr<Data::IClientRequest>));
	};
}

namespace CreateMocks
{
	// Client (from Client.h)
	std::unique_ptr<Mocks::ClientMock> ClientMock()
	{
		return std::make_unique<Mocks::ClientMock>();
	}
}

// Communication
// There is another namespace Mocks { ... }, for Communicators, on this document (Communication.h)
namespace Mocks {
	class ClientRequestMock : public Data::IClientRequest {
	public:
		MOCK_METHOD(uint8_t, getAuthByte, ());
		MOCK_METHOD(Data::Command, getCommand, ());
		MOCK_METHOD(const std::vector<uint8_t>, Serialize, ());
	};

	class ServerResponseMock : public Data::IServerResponse {
	public:
		MOCK_METHOD(bool, AuthSuccess, ());
		MOCK_METHOD(std::optional<Data::Command>, getCurrentTamagotchiCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getTamagotchiStatus, ());
		MOCK_METHOD(std::optional<Data::Animation>, getAnimation, ());
		MOCK_METHOD(const std::vector<uint8_t>, Serialize, ());
	};

	class StatusMock : public Data::IStatus, public Data::ISerializable {
	public:
		MOCK_METHOD(uint8_t, getHappiness, ());
		MOCK_METHOD(uint8_t, getAlertness, ());
		MOCK_METHOD(uint8_t, getStomachLevel, ());
		MOCK_METHOD(uint8_t, getCleaniness, ());
		MOCK_METHOD(const std::vector<uint8_t>, Serialize, ());
	};
}

// There is another namespace Mocks { ... }, for Data mocks, on this document (Communication.h)
namespace Mocks
{
	class RemoteResponderMock : public Communicators::IRemoteResponder
	{
	public:
		MOCK_METHOD(Communicators::rPtr, getSendFunction, ());
	};

	class SenderMock : public Communicators::ISender
	{
	public:
		MOCK_METHOD(const std::vector<uint8_t>, Send, (const std::vector<uint8_t>));
	};

	class ResponderMock : public Communicators::IResponder
	{
	public:
		MOCK_METHOD(void, Start, ());
		MOCK_METHOD(bool, getIsRunning, ());
		MOCK_METHOD(void, Stop, ());
		MOCK_METHOD(void, RegisterResponse, (Communicators::rPtr));
	};
}

namespace CreateMocks
{
	namespace CreateMocks
	{
		// Data:: (from Communication.h)
		std::unique_ptr<Mocks::ClientRequestMock> ClientRequestMock()
		{
			return std::make_unique<Mocks::ClientRequestMock>();
		}
		std::unique_ptr<Mocks::ServerResponseMock> ServerResponseMock()
		{
			return std::make_unique<Mocks::ServerResponseMock>();
		}
		std::unique_ptr<Mocks::StatusMock> StatusMock()
		{
			return std::make_unique<Mocks::StatusMock>();
		}

		// Comunicators:: (from Communication.h)
		std::unique_ptr<Mocks::RemoteResponderMock> RemoteResponderMock()
		{
			return std::make_unique<Mocks::RemoteResponderMock>();
		}
		std::unique_ptr<Mocks::ResponderMock> ResponderMock()
		{
			return std::make_unique<Mocks::ResponderMock>();
		}
		std::unique_ptr<Mocks::SenderMock> SenderMock()
		{
			return std::make_unique<Mocks::SenderMock>();
		}
	}
}


// Logger
namespace CreateMocks
{
	// Logger:: (from Logger.h)
	std::unique_ptr<Mocks::LogMock> LogMock()
	{
		return std::make_unique<Mocks::LogMock>();
	}
}

namespace Mocks {
	class LogMock : public Logger::ILog {
	public:
		MOCK_METHOD(time_t, getTime, ());
		MOCK_METHOD(const std::vector<uint8_t>, getData, ());
		MOCK_METHOD(Logger::action, getAction, ());
	};
}

// Server
// As Server is itself a Communicators::Responder, we can mock it via Mocks::ResponderMock
namespace Mocks
{
	typedef Mocks::ResponderMock ServerMock;
}

namespace CreateMocks
{
	// Server:: (from Server.h)
	std::unique_ptr<Mocks::ServerMock> ServerMock()
	{
		return std::make_unique<Mocks::ServerMock>();
	}
}

// Tamagotchi
namespace Mocks {
	class TamagotchiMock : public Tamagotchi::ITamagotchi {
	public:
		MOCK_METHOD(void, AddCommand, (Data::Command));
		MOCK_METHOD(void, AddCommand_Immediate, (Data::Command));
		MOCK_METHOD(Data::Command, GetCurrentCommand, ());
		MOCK_METHOD(std::unique_ptr<Data::IStatus>, getStatus, ());
		MOCK_METHOD(void, adjustStat, (Data::Stat, signed int relativeChange));
	};
}

namespace CreateMocks
{
	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Mocks::TamagotchiMock> TamagotchiMock()
	{
		return std::make_unique<Mocks::TamagotchiMock>();
	}
}