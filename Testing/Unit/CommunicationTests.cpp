#include "../../Communication/Create.h"
#include "../../Communication/Communication.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

  auto client = Create::ClientRequest();
}

TEST(ClientRequestTests, Constructor)
{
  auto client_request = Create::ClientRequest();
}

TEST(ClientRequestTests, GettersAndParameters)
{
  // Arrange
  uint8_t authbyte = 120;
  Data::Command command = Data::Command::clean;

  // Act
  auto client_request = Create::ClientRequest(authbyte, command);

  // Assert 
  EXPECT_EQ(client_request->getAuthByte(), 120) << "Authbyte was not the same!";
  EXPECT_EQ(client_request->getCommand(), command) << "Command was not the same!";
}