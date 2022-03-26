load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Communication",
    srcs = ["Communication.cpp"],
    hdrs = ["Communication.h"],
    visibility = [
        "//Client:__pkg__",
        "//Server:__pkg__",
        "//Tamagotchi:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//Testing/Mocks:__pkg__",
    ],
)

cc_library(
    name = "CreateCommunication",
    srcs = ["Create.cpp"],
    hdrs = ["Create.h"],
    visibility = ["//visibility:public"],
    deps = [ "//Communication:Communication" ]
)