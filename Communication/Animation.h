#pragma once
#include "IContainer.h"
#include <queue>
#include "IAnimation.h"

namespace Data
{
    class Animation : public IAnimation {
	public:
		std::queue<uint8_t> frames;

		Data::IContainer Serialize();
	};
} // namespace Data
