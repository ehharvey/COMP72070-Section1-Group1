#pragma once
#include "Tamagotchi.h"
#include <memory>

namespace Create
{
	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Tamagotchi::Tamagotchi> Tamagotchi()
	{
		return std::make_unique<Tamagotchi::Tamagotchi>(Tamagotchi::Tamagotchi());
	}
}

