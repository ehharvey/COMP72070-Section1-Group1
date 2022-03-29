#pragma once
#include "IContainer.h"
#include "Tamagotchi.h"
#include <memory>

// Example usage:
// #include "../Tamagotchi/Create.h"
// 
// ...
// auto tamagotchi = Create::Tamagotchi();
namespace Create
{
	// Tamagotchi:: (from Tamagotchi.h)
	std::unique_ptr<Tamagotchi::Tamagotchi> Tamagotchi();
}

