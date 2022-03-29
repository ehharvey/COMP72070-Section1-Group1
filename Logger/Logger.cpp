// Logger.cpp : Defines the functions for the static library.
//

#include "Logger.h"

Logger::Log::Log(action, Data::IContainer data)
{
}

std::time_t Logger::Log::getTime()
{
    return std::time_t();
}

Data::IContainer Logger::Log::getData()
{
    return Data::IContainer();
}

Logger::action Logger::Log::getAction()
{
    return action();
}
