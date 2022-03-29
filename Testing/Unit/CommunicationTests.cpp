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
  Data::CommandAction command = Data::CommandAction::clean;

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

// Remaining ServerResponse
// Tests needed for AuthSuccess
// Animation
// getCurrentTamagotchiCommand

TEST(StatusTests, ConstructorAndGetters)
{
  // Arrange
  uint8_t stat = 15;

  // Act
  auto actual = Create::Status(stat, stat, stat, stat);

  // Assert
  EXPECT_EQ(actual->getHappiness(), stat);
  EXPECT_EQ(actual->getCleaniness(), stat);
  EXPECT_EQ(actual->getAlertness(), stat);
  EXPECT_EQ(actual->getStomachLevel(), stat);
}

TEST(StatusTests, ConstructorAndGettersTwo)
{
  // Arrange

  // Act
  auto actual = Create::Status(1, 2, 3, 4);

  // Assert
  EXPECT_EQ(actual->getHappiness(), 1);
  EXPECT_EQ(actual->getCleaniness(), 2);
  EXPECT_EQ(actual->getAlertness(), 3);
  EXPECT_EQ(actual->getStomachLevel(), 4);
}

TEST(StatusTests, Serialization)
{
  // Arrange
  std::vector<uint8_t> Serialization;

  for (uint8_t i : {1,2,3,4})
  {
    Serialization.push_back(i);
  }

  // Act
  auto actual = Create::Status(Serialization);

  // Assert
  EXPECT_EQ(actual->Serialize(), Serialization);
}

TEST(StatusTests, setAlertness)
{
  // Arrange
  auto status = Create::Status(15, 15, 15, 15);

  // Act
  status->setAlertness(5);

  // Assert
  EXPECT_EQ(status->getAlertness(), 5);
}

TEST(Command, Serialization)
{
  // Arrange
  const std::vector<uint8_t> Serialization{5};

  // Act
  auto command = Create::Command(Serialization);

  // Assert
  EXPECT_EQ(command->Serialize(), Serialization);
}

TEST(Command, CommandAction)
{
  // Arrange
  Data::CommandAction action = Data::CommandAction::clean;

  // Act
  auto command = Create::Command(action);

  // Assert
  EXPECT_EQ(command->getAction(), action);
}