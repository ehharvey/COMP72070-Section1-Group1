load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Communication",
    srcs = ["Communication.cpp"],
    hdrs = ["Communication.h", "Create.h"],
    visibility = [
        "//Client:__pkg__",
        "//Server:__pkg__",
        "//Tamagotchi:__pkg__"
    ],
)