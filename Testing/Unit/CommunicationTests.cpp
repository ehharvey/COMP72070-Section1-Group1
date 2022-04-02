#pragma once
#include <ctime>
#include <random>
#include "../../Communication/Create.h"
#include "../Mocks/Mocks.h"
#include <gtest/gtest.h>


// TODO
TEST(ISerializables, SerializationAndDeserialization)
{
  std::vector<Data::ISerializable> testees = {};

  for (auto & t: testees)
  {
    auto serialization = t.Serialize();
  }
}

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