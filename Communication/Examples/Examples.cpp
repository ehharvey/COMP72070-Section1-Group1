#include "../Communication.h";
#include "../Create.h";
#include <iostream>

// Declared const so that myFunc does not get redefined
const Communicators::rPtr myFunc = [](std::vector<uint8_t> request)
{
	// Retrieves an integer
	int request_integer;
	std::memcpy((void*) &request_integer, (void*) request.front(), sizeof(int));

	request_integer++;

	std::vector<uint8_t> result(sizeof(int)); // Initializes the vector with ~4 bytes
	std::memcpy((void*) result.front(), &request_integer, sizeof(int));

	return result;
};

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