#pragma once


namespace Client {
	const int EXPECTED_FOO = 3;

	int getFOO();

	class Client {
	private:
		/*
		* Variables:
		* - IP address
		* - ClientRequest 
		*/
		Communication::ClientRequest ClientRequest;
	};
}
