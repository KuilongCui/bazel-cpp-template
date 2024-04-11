load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [
        "@com_github_google_glog//:glog",
        "@com_github_gflags_gflags//:gflags",
    ]
)
