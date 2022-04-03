#include "Create.h"

// Tamagotchi:: (from Tamagotchi.h)
std::unique_ptr<Tamagotchi::Tamagotchi> Create::Tamagotchi()
{
	auto new_status = Create::Status(15, 15, 15, 15);
	return std::make_unique<Tamagotchi::Tamagotchi>(Tamagotchi::Tamagotchi(std::move(new_status)));
}
