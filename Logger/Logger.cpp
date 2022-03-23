// Logger.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Logger.h"

Logger::Log::Log(Logger::action action, const std::vector<uint8_t> data)
	:data(data),
	a(action)
{ }

std::time_t Logger::Log::getTime() {
	return std::time_t();
}

const std::vector<uint8_t> Logger::Log::getData() {
	const std::vector<uint8_t> ret;
	return ret;
}