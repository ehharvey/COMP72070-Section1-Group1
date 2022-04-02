#pragma once
#include "IContainer.h"
#include "ISerializable.h"
#include <string>
#include <array>

namespace Data
{
    struct IPV4Address
	{
		uint8_t octet[4];

		std::string ToString();
	};

	const auto MAX_PACKET_SIZE = 2048;

	struct Transmission
	{
		struct __header
		{
			uint16_t transmit_size;
			uint8_t more_incoming;
		} header;

		std::array<uint8_t, MAX_PACKET_SIZE> data;
	};
} // namespace Data
