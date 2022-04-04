#pragma once
#include <ctime>
#include <random>
#include "../../Communication/Create.h"
#include <gtest/gtest.h>


TEST(ClientRequest, SerializationIsCorrect)
{
    auto authorization = Data::Authorization::New(5);
    auto command = Data::Command::New({1});

  
    auto client_request = Create::ClientRequest(std::move(authorization), std::move(command));

    auto client_serialization = client_request->Serialize();

    EXPECT_EQ(client_serialization, Data::IContainer({
      0, 1, 5, // Authorization
      1, 1, 1  // Command
    }));
}

TEST(AuthorizationTests, SerializationToByte)
{
  // Arrange
  std::random_device rd;
  std::mt19937 gen(rd());

  uint8_t byte =  (uint8_t) gen();

  // Act
  auto authorization = Data::Authorization::New(byte);

  EXPECT_EQ(authorization->getAuthByte(), byte);
}

TEST(AuthorizationTests, SerializationToIContainer)
{
  // Arrange
  std::random_device rd;
  std::mt19937 gen(rd());

  uint8_t byte =  (uint8_t) gen();

  // Act
  auto authorization = Data::Authorization::New(byte);

  EXPECT_EQ(authorization->Serialize(), Data::IContainer(1, byte));
}

TEST(Status, constructor)
{
  // Arrange
  uint8_t value = 5;

  // Act
  auto status = Create::Status(value, value, value, value);

  // Assert
  EXPECT_EQ(status->getAlertness(), value);
  EXPECT_EQ(status->getHappiness(), value);
  EXPECT_EQ(status->getCleaniness(), value);
  EXPECT_EQ(status->getStomachLevel(), value);
}

TEST(Status, updater)
{
  // Arrange
  uint8_t value = 5;

  // Act
  auto status = Create::Status(value, value, value, value);
  status->setAlertness(value - 1);
  status->setCleaniness(value - 1);
  status->setHappiness(value - 1);
  status->setStomachLevel(value - 1);

  // Assert
  EXPECT_EQ(status->getAlertness(), value - 1);
  EXPECT_EQ(status->getCleaniness(), value - 1);
  EXPECT_EQ(status->getStomachLevel(), value - 1);
  EXPECT_EQ(status->getHappiness(), value - 1);
}

TEST(Status, serialization)
{
  // Arrange
  uint8_t value = 5;

  // Act
  auto status = Create::Status(value, value, value, value);
  auto serialization = status->Serialize();
  auto copy = Create::Status(serialization);

  // Assert
  EXPECT_EQ(copy->getAlertness(), status->getAlertness());
}

TEST(Command, constructor_and_getter)
{
  // Arrange
  auto command = Create::Command(Data::CommandAction::idle);

  // Act
  auto actual = command->getAction();

  // Assert
  EXPECT_EQ(command->getAction(), actual);
}

TEST(Command, Serialization)
{
  // Arrange
  auto command = Create::Command(Data::CommandAction::idle);

  // Act
  auto actual = command->Serialize();
  auto copy = Create::Command(actual);

  // Assert
  EXPECT_EQ(copy->getAction(), command->getAction());
  EXPECT_EQ(copy->getAction(), Data::CommandAction::idle);
}

TEST(ServerResponse, serialization)
{
  auto result = Data::Result::New(false);
  auto server_response = Create::ServerResponse(std::move(result));
  auto serialization = server_response->Serialize();
  auto copy = Create::ServerResponse(serialization);

  EXPECT_EQ(copy->getResult().value()->AuthSuccess(), server_response->getResult().value()->AuthSuccess());
}