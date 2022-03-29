#pragma once
#include "rPtr.h"

namespace Communicators
{
    __interface IRemoteResponder
	{
		// To use:
		// {
		//		auto remote_responder = Create::MockRemoteResponder();
		//		auto send_function = remote_responder.getSendFunction();
		//
		//		std::vector<uint8_t> payload = { 'h', 'e', 'l', 'l', 'o' };
		//		auto server_response = send_function(payload);
		// }
		rPtr getSendFunction();
	};

} // namespace 
