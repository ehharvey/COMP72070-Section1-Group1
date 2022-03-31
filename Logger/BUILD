load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Logger",
    srcs = ["Logger.cpp"],
    hdrs = ["Logger.h"],
    visibility = [
        "//Client:__pkg__",
        "//ClientCLI:__pkg__",
        "//Server:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//Testing/Mocks:__pkg__",
    ],
    deps = ["//Communication:Create"],
)

cc_library(
    name = "CreateLogger",
    srcs = ["Create.cpp"],
    hdrs = ["Create.h"],
    visibility = ["//visibility:public"],
    deps = [ "//Logger:Logger" ]
)