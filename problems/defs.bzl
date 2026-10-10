load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("@rules_python//python:defs.bzl", "py_library", "py_test")

def leetcode_problem(name = None, extra_cc_deps = [], extra_py_deps = []):
    pkg_name = native.package_name().split("/")[-1]
    prob_name = name or pkg_name

    cc_library(
        name = prob_name,
        srcs = [prob_name + ".cc"],
        hdrs = [prob_name + ".h"],
        deps = extra_cc_deps,
        visibility = ["//visibility:public"],
    )

    cc_test(
        name = prob_name + "_cc_test",
        srcs = [prob_name + "_test.cc"],
        tags = ["cc"],
        deps = [
            ":" + prob_name,
            "@googletest//:gtest_main",
        ] + extra_cc_deps,
    )

    native.test_suite(
        name = "cc_test",
        tags = ["cc"],
        tests = [":" + prob_name + "_cc_test"],
    )

    py_library(
        name = prob_name + "_py",
        srcs = [prob_name + ".py"],
        imports = ["."],
        deps = extra_py_deps,
        visibility = ["//visibility:public"],
    )

    py_test(
        name = prob_name + "_py_test",
        srcs = [
            "//tools:pytest_runner.py",
            prob_name + ".py",
            prob_name + "_test.py",
        ],
        main = "//tools:pytest_runner.py",
        imports = ["."],
        tags = ["py"],
        args = [native.package_name() + "/" + prob_name + "_test.py"],
        deps = [
            ":" + prob_name + "_py",
            "@pip//pytest",
        ] + extra_py_deps,
    )

    native.test_suite(
        name = "py_test",
        tags = ["py"],
        tests = [":" + prob_name + "_py_test"],
    )

    native.test_suite(
        name = "test",
        tests = [
            ":" + prob_name + "_cc_test",
            ":" + prob_name + "_py_test",
        ],
    )
