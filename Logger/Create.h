#pragma once
#include "Logger.h"
#include <memory>

namespace Create
{
	// Logger:: (from Logger.h)
	std::unique_ptr<Logger::Log> Log(Logger::action a, const std::vector<uint8_t> data)
	{
		return std::make_unique<Logger::Log>(Logger::Log(a, data));
	}
}