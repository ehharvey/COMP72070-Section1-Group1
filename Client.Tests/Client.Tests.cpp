#include "pch.h"
#include "Client.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ClientTests
{
	TEST_CLASS(ClientTests)
	{
	public:
		
		TEST_METHOD(getFoo_void_3)
		{
			Assert::AreEqual(Client::EXPECTED_FOO, Client::getFOO());
;		}
	};
}
