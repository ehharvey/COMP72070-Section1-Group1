load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Tamagotchi",
    srcs = ["Tamagotchi.cpp"],
    hdrs = ["Tamagotchi.h"],
    deps = ["//Communication:Communication"],
    visibility = [
        "//Client:__pkg__",
        "//ClientCLI:__pkg__",
        "//Server:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//Testing/Mocks:__pkg__",
    ],
)

cc_library(
    name = "CreateTamagotchi",
    srcs = ["Create.cpp"],
    hdrs = ["Create.h"],
    visibility = ["//visibility:public"],
    deps = [ "//Tamagotchi:Tamagotchi" ]
)