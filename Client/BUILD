load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Client",
    srcs = ["Client.cpp"],
    hdrs = ["Client.h", "Create.h"],
    visibility = [
        "//ClientCLI:__pkg__",
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//Testing/Mocks:__pkg__",
        "//Client:__pkg__",
        ],
    deps = [ "//Communication:Communication" ]
)

cc_library(
    name = "CreateClient",
    srcs = ["Create.cpp"],
    hdrs = ["Create.h"],
    visibility = ["//visibility:public"],
    deps = [ "//Client:Client" ]
)