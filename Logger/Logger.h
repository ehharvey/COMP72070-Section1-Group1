#pragma once
#include <ctime>
#include <vector>

namespace Logger {
	enum action {
		transmit,
		receive
	};

	__interface ILog
	{
		std::time_t getTime();
		const std::vector<uint8_t> getData();
		action getAction();
	};



	class Log : public ILog {
	private:
		action a;
		std::vector<uint8_t> data;
	public:
		Log(action, const std::vector<uint8_t> data);
		std::time_t getTime();
		const std::vector<uint8_t> getData();
		action getAction();
	};
}