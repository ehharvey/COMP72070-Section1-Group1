#pragma once
#include <gtest/gtest.h>
#include "../Mocks/Mocks.h"
#include "../../Client/Create.h"

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(ClientTests, SendCommandTest)
{
  
  auto sender_mock = CreateMocks::SenderMock();

  EXPECT_CALL(*sender_mock, Send)
    .Times(1)
    .WillOnce([](const std::vector<uint8_t> message) {
      return std::vector<uint8_t>();
    });

  auto response_parser = [](const std::vector<uint8_t> response_serialization) {
    auto server_response_mock = CreateMocks::ServerResponseMock();

    EXPECT_CALL(*server_response_mock, AuthSuccess)
      .Times(1)
      .WillOnce([]() {
        return true;
      });

    EXPECT_CALL(*server_response_mock, Serialize)
      .Times(1)
      .WillOnce([]() {
        return std::vector<uint8_t>({ 200 });
      });
    return std::move(server_response_mock);
  };

  auto client = Create::Client(std::move(sender_mock));
  client->__setResponseParser(response_parser);

  auto client_request_mock = CreateMocks::ClientRequestMock();

  EXPECT_CALL(*client_request_mock, Serialize)
    .Times(1)
    .WillOnce([]() {
      return std::vector<uint8_t>();
    });

  auto response = client->SendCommand(std::move(client_request_mock));

  EXPECT_EQ(response->AuthSuccess(), false) << "Client did not return mock";
  EXPECT_EQ(response->Serialize(), std::vector<uint8_t>({ 100 }));
  EXPECT_EQ(10, 20);
}