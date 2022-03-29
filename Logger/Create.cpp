#include "Create.h"

namespace Create
{
	// Logger:: (from Logger.h)
	std::unique_ptr<Logger::Log> Log(Logger::action a, Data::IContainer data)
	{
		return std::make_unique<Logger::Log>(Logger::Log(a, data));
	}
}