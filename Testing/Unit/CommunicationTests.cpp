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

TEST(ClientRequestTests, SerializationIsConsistent)
{
  // Arrange
  std::vector<uint8_t> serialization;

  for (auto i : {1, 2, 3, 4})
  {
    serialization.push_back(i);
  }

  // Act
  auto actual = Create::ClientRequest(serialization);

  // Assert
  EXPECT_EQ(serialization, actual->Serialize()) << "The serialization was not consistent!";
}

TEST(ServerResponseTests, DefaultConstructor)
{
  auto server_response = Create::ServerResponse(); // shouldn't crash
}

TEST(ServerResponseTests, ConsistentSerialization)
{
  // Arrange
  std::vector<uint8_t> serialization;

  for (uint8_t i: {1, 2, 3, 4})
  {
    serialization.push_back(i);
  }

  // Act
  auto actual = Create::ServerResponse(serialization);

  // Assert
  EXPECT_EQ(serialization, actual->Serialize()) << "The serialization was not consistent!";
}