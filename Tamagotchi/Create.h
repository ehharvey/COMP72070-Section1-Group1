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

namespace CreateMocks
{
	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Mocks::TamagotchiMock> TamagotchiMock()
	{
		return std::make_unique<Mocks::TamagotchiMock>();
	}
}