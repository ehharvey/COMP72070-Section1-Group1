#pragma once
#include "IContainer.h"
#include <memory>
#include <functional>

namespace Data
{
    __interface ISerializable
	{
		Data::IContainer Serialize();
	};

	typedef std::function<std::unique_ptr<ISerializable>(Data::IContainer)> ISerializableConstructor;
}