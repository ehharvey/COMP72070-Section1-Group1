#pragma once
#include "IContainer.h"
#include <vector>
#include <functional>

namespace Communicators
{
    // rPtr: a lambda function indicating the response to an input
	// - Needs to be a function that receives a Data::IContainer	<---- (the request)
	// - This function needs to also return a Data::IContainer		<---- (the response)
	typedef std::function<Data::IContainer(Data::IContainer)> rPtr;
} // namespace Communicators
