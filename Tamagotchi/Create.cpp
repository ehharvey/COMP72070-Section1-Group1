#include "Create.h"

// Tamagotchi:: (from Tamagotchi.h)
std::unique_ptr<Tamagotchi::Tamagotchi> Create::Tamagotchi()
{
	return std::make_unique<Tamagotchi::Tamagotchi>(Tamagotchi::Tamagotchi());
}
