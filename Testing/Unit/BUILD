cc_test(
  name = "Client",
  size = "small",
  srcs = ["ClientTests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Client:CreateClient",
    "//Testing/Mocks:Mocks",
  ],
)

cc_test(
  name = "Communication",
  size = "small",
  srcs = ["CommunicationTests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Communication:Create",
    "//Testing/Mocks:Mocks"
  ],
)

cc_test(
  name = "Logger",
  size = "small",
  srcs = ["LoggerTests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Logger:CreateLogger",
  ],
)

cc_test(
  name = "Server",
  size = "small",
  srcs = ["ServerTests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Server:CreateServer",
  ],
)

cc_test(
  name = "Tamagotchi",
  size = "small",
  srcs = ["TamagotchiTests.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//Tamagotchi:CreateTamagotchi",
  ],
)