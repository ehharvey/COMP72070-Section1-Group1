load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Server",
    srcs = ["Server.cpp"],
    hdrs = ["Server.h", "Create.h"],
    deps = [ 
        "//Communication:Communication",
        "//Tamagotchi:Tamagotchi"
    ],
    visibility = [
        "//Testing:__pkg__",
        "//Testing/Unit:__pkg__",
        "//ClientCLI:__pkg__",
        "//Testing/Mocks:__pkg__",
    ],
)