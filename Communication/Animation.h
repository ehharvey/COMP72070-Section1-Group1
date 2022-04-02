#pragma once
#include "IContainer.h"
#include <queue>
#include "IAnimation.h"

namespace Data
{
    class Animation : public IAnimation {
	public:
		Animation(IContainer Serialization);
		Data::IContainer Serialize () const;
	};
} // namespace Data
