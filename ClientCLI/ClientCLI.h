#pragma once
#include "..\Communication\Create.h"
#include "..\Logger\Create.h"
#include "..\Server\Create.h"
#include "..\Tamagotchi\Create.h"
#include "..\Client\Create.h"
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

std::optional<uint8_t> getAuthByte(std::string auth_str);

// This is a test