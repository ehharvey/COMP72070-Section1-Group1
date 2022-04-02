#pragma once
#include "IContainer.h"
#include <queue>
#include "IAnimation.h"
#include <typeindex>
#include <memory>

namespace Data
{
    class Animation : public IAnimation {
		uint8_t item;
	public:
		Animation();
		Animation(IContainer Serialization);
		Data::IContainer Serialize () const;

		static std::unique_ptr<Animation> New();
		static std::unique_ptr<Animation> Deserialize(Data::IContainer Serialization);
	};

	const std::pair<std::type_index, Data::ISerializableConstructor> animation_type_constructor =
		std::make_pair<std::type_index, Data::ISerializableConstructor>
		(std::type_index(typeid(Animation)), Data::Animation::Deserialize);
} // namespace Data
