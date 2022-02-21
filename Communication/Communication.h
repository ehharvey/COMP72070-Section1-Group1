#pragma once

namespace Communication {
	const int HELLO = 1;

	struct ClientRequest {
		unsigned char AuthByte;
		unsigned char CommandByte;
	};
}