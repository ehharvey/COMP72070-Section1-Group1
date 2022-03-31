#pragma once
#include "IContainer.h"
#include <queue>
#include "IAnimation.h"

namespace Data
{
    class Animation : public IAnimation {
	public:
		Animation(IContainer Serialization);
		std::queue<uint8_t> frames;

		Data::IContainer Serialize();
	};
} // namespace Data
