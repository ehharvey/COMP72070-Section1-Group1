// Logger.cpp : Defines the functions for the static library.
//
#include <iomanip>
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

void
Logger::Log::AppendToFile(std::fstream f)
{
    if (!f.is_open())
    {
        std::cerr << "Logger: File is not open!\n";
        return;
    }
    f.seekg(0, std::ios::end);

    char timeStr[25];
    std::strftime(timeStr, 25, "%F %T%t", (const tm*)&(this->time));
    f << timeStr;

    switch (this->a)
    {
    case Logger::action::receive:
        f << "Rx\t";
        break;
    case Logger::action::transmit:
        f << "Tx\t";
        break;
    }

    for (auto const & i : this->data)
    {
        char dataStr[3]; // 255 is the max value of a single byte
        _itoa_s(i, dataStr, 10);

        f << dataStr;
    }
    f << "\n";
}