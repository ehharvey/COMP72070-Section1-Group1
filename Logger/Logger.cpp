// Logger.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Logger.h"

Logger::Log::Log(Logger::action action, Communication::IData& data) {
	this->a = action;
	this->data = data;
}

std::time_t Logger::Log::getTime() {
	return std::time_t();
}

Communication::Data Logger::Log::getData() {
	Communication::Data ret;
	return ret;
}