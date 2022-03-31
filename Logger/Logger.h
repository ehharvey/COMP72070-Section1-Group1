#pragma once
#include <ctime>
#include <vector>
#include "../Communication/Create.h"

namespace Logger {
	enum action {
		transmit,
		receive
	};

	__interface ILog
	{
		std::time_t getTime();
		Data::IContainer getData();
		action getAction();
	};



	class Log : public ILog {
	private:
		action a;
		Data::IContainer data;
	public:
		Log(action, Data::IContainer data);
		std::time_t getTime();
		Data::IContainer getData();
		action getAction();
	};
}