#pragma once
#include "Logger.h"
#include <memory>

// Example usage:
// #include "../Logger/Create.h"
// 
// ...
// auto a = Logger::action::Receive;
// auto data = std::vector<uint8_t>();
// 
// auto log = Create::Log(a, data);
namespace Create
{
	// Logger:: (from Logger.h)
	std::unique_ptr<Logger::Log> Log(Logger::action a, const std::vector<uint8_t> data);
}