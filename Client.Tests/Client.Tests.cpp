#include "pch.h"
#include "CppUnitTest.h"
#include "Client.h"
#include "Communication.h"
#include "gmock/gmock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ClientTests
{
	TEST_CLASS(ClientTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			CommunicationMocks::MockData md;

			ON_CALL(md, getSize).WillByDefault(testing::Return(5));

			Assert::AreEqual(5, (int)md.getSize());
		}
	};
}
