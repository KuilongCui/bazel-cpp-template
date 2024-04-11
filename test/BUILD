load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    size = "small",
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "sort_test",
    srcs = ["sort_test.cc"],
    size = "small",
    deps = [
        "@com_google_googletest//:gtest_main",
        "//src/lib/sort:SortLib"
    ],
)
