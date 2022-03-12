#include "pch.h"
#include "CppUnitTest.h"
#include "Communication.h"
#include "gmock/gmock.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(CommunicationTests)
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
			// shouldn't crash
		}
	};
}
