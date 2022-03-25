load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Logger",
    srcs = ["Logger.cpp"],
    hdrs = ["Logger.h", "Create.h"],
    visibility = [
        "//Client:__pkg__",
        "//ClientCLI:__pkg__",
        "//Server:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
    ],
)