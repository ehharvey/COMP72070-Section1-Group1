load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Tamagotchi",
    srcs = ["Tamagotchi.cpp"],
    hdrs = ["Tamagotchi.h", "Create.h"],
    deps = ["//Communication:Communication"],
    visibility = [
        "//Client:__pkg__",
        "//ClientCLI:__pkg__",
        "//Server:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
    ],
)