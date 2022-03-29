#pragma once
#include <queue>
#include "IAnimation.h"

namespace Data
{
    class Animation : public IAnimation {
	public:
		std::queue<uint8_t> frames;

		const std::vector<uint8_t> Serialize();
	};
} // namespace Data
