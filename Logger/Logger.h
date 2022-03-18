#pragma once
#pragma once
#include "..\Communication\Communication.h"
#include <ctime>
#include "gmock/gmock.h"

namespace Logger {
	enum action {
		transmit,
		receive
	};

	__interface ILog
	{
		std::time_t getTime();
		Communication::IData& getData();
		action getAction();
	};



	class Log : public ILog {
	public:
		Log(action, Communication::IData& data);
		std::time_t getTime();
		Communication::IData& getData();
	};
}

namespace LoggerMocks {
	class MockLogger : public Logger::ILog {
		MOCK_METHOD(time_t, getTime, ());
		MOCK_METHOD(Communication::IData&, getData, ());
	};
}