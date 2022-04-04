#include "Create.h"
#include <random>

// Tamagotchi:: (from Tamagotchi.h)
std::unique_ptr<Tamagotchi::Tamagotchi> Create::Tamagotchi()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	uint8_t byte = (uint8_t)gen();

	auto new_status = Create::Status(15, 15, 15, 15);
	auto auth = Data::Authorization::New(byte);
	return std::make_unique<Tamagotchi::Tamagotchi>(Tamagotchi::Tamagotchi(std::move(new_status), std::move(auth)));
}
