load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "ClientCLI",
    srcs = ["ClientCLI.cpp"],
    visibility = [
        "//Testing:__pkg__",
    ],
    deps = [
            "//Client:Client"
    ],
)