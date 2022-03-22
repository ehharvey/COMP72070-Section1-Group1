#include "pch.h"
#include "CppUnitTest.h"
#include "Communication.h"
#include "gmock/gmock.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Data_TESTS)
	{
	public:
			
		TEST_METHOD(ConstructorTest)
		{
			// Arrange
			std::string payload = "Hello World";
			size_t size = payload.length() + 1;

			
			// Act
			Communication::IData& myData = Communication::Data((uint8_t*)payload.c_str(), size);
			
			// Assert
			Assert::AreEqual(EXPECTED_SIZE, myData.getSize());
		}

		TEST_METHOD(getPayloadCheck) {
			// Arrange
			std::unique_ptr<const uint8_t> s(new const uint8_t[]{ "Hello World" });
			const size_t SIZE = strlen("Hello World") + 1;


			// Act
			Communication::Data myData = Communication::Data(std::move(s), SIZE);

			// Assert
			bool payload_is_the_same = strcmp("Hello World", (const char*)(myData.getPayload().get())) == 0;
			Assert::IsTrue(payload_is_the_same);
		}
	};

	TEST_CLASS(ClientRequest_TESTS) 
	{
	private:
	public:
		TEST_METHOD(Constructor) {
			// Arrange

			// Act

			// Assert
			Communication::ClientRequest actual; // Shouldn't crash
		}

		TEST_METHOD(INCOMPLETE_ConstructorDeserialization) {
			// Arrange
			const Communication::ClientRequest EXPECTED;

			// Act
			Communication::ClientRequest actual(std::unique_ptr<Communication::IData>(new Communication::Data()));

			// Assert
			
		}
	};
}
