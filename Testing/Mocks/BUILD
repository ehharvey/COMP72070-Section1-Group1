load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Mocks",
    visibility = ["//Testing/Unit:__pkg__"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "//Client:Client",
        "//Communication:Communication",
        "//Logger:Logger",
        "//Server:Server",
        "//Tamagotchi:Tamagotchi",
    ],
    hdrs = ["Mocks.h"],
)