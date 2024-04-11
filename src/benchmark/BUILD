load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "sort_benchmark",
    srcs = ["sort_benchmark.cc"],
    deps = [
        "@com_google_benchmark//:benchmark",
        "//src/lib/sort:SortLib"
    ],
)
