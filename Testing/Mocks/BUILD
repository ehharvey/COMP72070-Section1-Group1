load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Communication",
    hdrs = ["Communication.h"],
    visibility = ["//Testing:__subpackages__"],
)

cc_library(
    name = "Mocks",
    visibility = ["//Testing/Unit:__pkg__"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "//Client:Client",
        "//Communication:Create",
        "//Logger:Logger",
        "//Server:Server",
        "//Tamagotchi:Tamagotchi",
        "//Testing/Mocks:Communication"
    ],
    hdrs = ["Mocks.h"],
)