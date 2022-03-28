load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "ClientCLIHeaders",
    deps = [
            "//Client:CreateClient",
            "//Logger:CreateLogger",
            "//Server:CreateServer",
    ],
    visibility = [
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//Testing/Mocks:__pkg__",
    ],
    hdrs = ["ClientCLI.h"],
    srcs = ["ClientCLI.cpp"],
)

cc_binary(
    name = "ClientCLI",
    srcs = ["ClientCLI.cpp"],
    deps = ["ClientCLIHeaders"]
)