#include "../Communication.h";
#include "../Create.h";
#include <iostream>

void __TcpHost_Example()
{
	Data::IPV4Address test = { 192, 168, 100, 1 };
	static auto function = [](std::vector<uint8_t>) {
		return std::vector<uint8_t>();
	};
	
    auto tcp_host = Create::TcpHost(test, function);
}

int main()
{
	__TcpHost_Example();

	std::cout << "Hello, World!\n";

	return 0;
}