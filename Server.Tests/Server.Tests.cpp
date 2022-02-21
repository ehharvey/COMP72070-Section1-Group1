#include "pch.h"
#include "CppUnitTest.h"
#include "..\Server\Server.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ServerTests
{
	TEST_CLASS(ServerTests)
	{
	public:
		
		TEST_METHOD(getFoo_void_3)
		{
			Assert::AreEqual(Server::EXPECTED_FOO, Server::getFOO());
		}
	};
}
