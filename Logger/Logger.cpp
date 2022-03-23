// Logger.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Logger.h"

Logger::Log::Log(action, const std::vector<uint8_t> data)
{
}

std::time_t Logger::Log::getTime()
{
    return std::time_t();
}

const std::vector<uint8_t> Logger::Log::getData()
{
    return std::vector<uint8_t>();
}

Logger::action Logger::Log::getAction()
{
    return action();
}
