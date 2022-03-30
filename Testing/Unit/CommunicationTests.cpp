#include <ctime>
#include <random>
#include "../../Communication/Create.h"
#include "../Mocks/Mocks.h"
#include <gtest/gtest.h>

TEST(AuthorizationTests, Serialization)
{
  // Arrange
  std::random_device rd;
  std::mt19937 gen(rd());

  uint8_t byte =  (uint8_t) gen();

  // Act
  auto authorization = Data::Authorization::New(byte);

  EXPECT_EQ(authorization->getAuthByte(), byte);
}

TEST(AuthorizationTests, Serialization)
{
  // Arrange
  std::random_device rd;
  std::mt19937 gen(rd());

  uint8_t byte =  (uint8_t) gen();

  // Act
  auto authorization = Data::Authorization::New(byte);

  EXPECT_EQ(authorization->Serialize(), Data::IContainer(1, byte));
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
  EXPECT_EQ(client_request->getAuthorization()->Serialize()[0], 120) << "Authbyte was not the same!";
  EXPECT_EQ(client_request->getCommand()->getAction(), command) << "Command was not the same!";
}

TEST(ClientRequestTests, SerializationIsConsistent)
{
  // Arrange
  Data::IContainer serialization;

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
  Data::IContainer serialization;

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
  Data::IContainer Serialization;

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
  Data::IContainer Serialization{5};

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

TEST(TcpHostTests, Idles)
{
  auto response_function = [](Data::IContainer request)
  {
    return Data::IContainer{1, 2, 3, 4};
  };

  Data::IPV4Address localhost{127, 0, 0, 1};

  auto tcp_host = Create::TcpHost(localhost, response_function);

  // act
  //tcp_host->Start();

  // Assert
  EXPECT_EQ(tcp_host->getIsRunning(), false);
}

TEST(TcpHostTests, Start)
{
  auto response_function = [](Data::IContainer request)
  {
    return Data::IContainer{1, 2, 3, 4};
  };

  Data::IPV4Address localhost{127, 0, 0, 1};

  auto tcp_host = Create::TcpHost(localhost, response_function);

  // act
  tcp_host->Start();

  // Assert
  EXPECT_EQ(tcp_host->getIsRunning(), true);
}

TEST(TcpClientTests, Send)
{
  auto mock_responder = Mocks::RemoteResponderMock::New();

  auto send_function = [](Data::IContainer request)
  {
    return Data::IContainer{1, 2};
  };

  Data::IPV4Address localhost{127, 0, 0, 1};

  EXPECT_CALL(*mock_responder, getSendFunction)
    .Times(1)
    .WillOnce([&]()
    {
      return send_function;
    });
  
  auto tcp_client = Create::TcpClient(localhost, std::move(mock_responder));

  auto actual = tcp_client->Send({1, 2,3});
  auto EXPECTED = Data::IContainer{1, 2};
  EXPECT_EQ(actual, EXPECTED);
}