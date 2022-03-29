#pragma once
#include "IContainer.h"
#include "rPtr.h"

namespace Communicators
{
    __interface IResponder
	{
		// This function does not return anything. It receives a pointer to another function as a parameter (you can use lambda instead)
		//
		// The lambda should do a few things:
		// - It should take in a Data::IContainer		<-- This will be the data that the client sent to the server as a [request]
		// - It should return a Data::IContainer		<-- This will be the data that will sent *back* to the client as a [response]
		void RegisterResponse(rPtr);

		void Start();
		void Stop();
		bool getIsRunning();
	};
} // namespace Communicators
