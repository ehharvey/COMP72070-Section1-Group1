#pragma once
#include <gtest/gtest.h>
#include "../Mocks/Mocks.h"
#include "../../Client/Create.h"


TEST(ClientTests, SendCommandTest)
{
  // Arrange
  //auto sender_mock = CreateMocks::SenderMock();

  // EXPECT_CALL(*sender_mock, Send)
  //   .Times(1)
  //   .WillOnce([](const std::vector<uint8_t> message) {
  //     return std::vector<uint8_t>();
  //   });

  // auto response_parser = [](const std::vector<uint8_t> response_serialization) {
  //   auto server_response_mock = Create::Mocks::ServerResponseMock();

  //   EXPECT_CALL(*server_response_mock, AuthSuccess)
  //     .Times(1)
  //     .WillOnce([]() {
  //       return true;
  //     })

  //   EXPECT_CALL(*server_response_mock, Serialize)
  //     .Times(1)
  //     .WillOnce([]() {
  //       return std::vector<uint8_t>({ 200 });
  //     })
  //   return std::move(server_response_mock);
  // }

  // auto client = Create::Client(std::move(sender_mock), response_parser);

  // auto client_request_mock = Create::Mocks::ClientRequestMock();

  // EXPECT_CALL(*client_request_mock, Serialize)
  //   .Times(1)
  //   .WillOnce([]() {
  //     return std::vector<uint8_t>();
  //   })

  // client->SendCommand(std::move(client_request_mock));
}