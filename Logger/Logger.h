#pragma once
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
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
		void AppendToFile(std::fstream f);
	};



	class Log : public ILog {
	private:
		action a;
		Data::IContainer data;
		std::time_t time;
	public:
		Log(action, Data::IContainer data);
		std::time_t getTime();
		Data::IContainer getData();
		action getAction();
		void AppendToFile(std::fstream f);
	};
}