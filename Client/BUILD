load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Client",
    srcs = ["Client.cpp"],
    hdrs = ["Client.h", "Create.h"],
    visibility = [
        "//ClientCLI:__pkg__",
        "//Testing:__pkg__",
        ],
    deps = [ "//Communication:Communication"]
)