load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("@rules_python//python:defs.bzl", "py_library", "py_test")

def leetcode_problem(name = None, variants = [], extra_cc_deps = [], extra_py_deps = []):
    pkg_name = native.package_name().split("/")[-1]
    prob_name = name or pkg_name

    if not variants:
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
    else:
        cc_test_targets = []
        py_test_targets = []

        for v in variants:
            target_cc_lib = prob_name + "_" + v
            target_cc_test = prob_name + "_" + v + "_cc_test"
            target_py_lib = prob_name + "_" + v + "_py"
            target_py_test = prob_name + "_" + v + "_py_test"

            cc_library(
                name = target_cc_lib,
                srcs = [prob_name + "_" + v + ".cc"],
                hdrs = [prob_name + ".h"],
                deps = extra_cc_deps,
                visibility = ["//visibility:public"],
            )

            cc_test(
                name = target_cc_test,
                srcs = [prob_name + "_test.cc"],
                tags = ["cc"],
                deps = [
                    ":" + target_cc_lib,
                    "@googletest//:gtest_main",
                ] + extra_cc_deps,
            )
            cc_test_targets.append(":" + target_cc_test)

            py_library(
                name = target_py_lib,
                srcs = [prob_name + "_" + v + ".py"],
                imports = ["."],
                deps = extra_py_deps,
                visibility = ["//visibility:public"],
            )

            py_test(
                name = target_py_test,
                srcs = [
                    "//tools:pytest_runner.py",
                    prob_name + "_" + v + ".py",
                    prob_name + "_test.py",
                ],
                main = "//tools:pytest_runner.py",
                imports = ["."],
                tags = ["py"],
                env = {
                    "LEETCODE_SOLUTION_MODULE": prob_name + "_" + v,
                },
                args = [native.package_name() + "/" + prob_name + "_test.py"],
                deps = [
                    ":" + target_py_lib,
                    "@pip//pytest",
                ] + extra_py_deps,
            )
            py_test_targets.append(":" + target_py_test)

        native.alias(
            name = prob_name,
            actual = ":" + prob_name + "_" + variants[0],
            visibility = ["//visibility:public"],
        )

        native.alias(
            name = prob_name + "_py",
            actual = ":" + prob_name + "_" + variants[0] + "_py",
            visibility = ["//visibility:public"],
        )

        native.test_suite(
            name = "cc_test",
            tags = ["cc"],
            tests = cc_test_targets,
        )

        native.test_suite(
            name = "py_test",
            tags = ["py"],
            tests = py_test_targets,
        )

        native.test_suite(
            name = "test",
            tests = cc_test_targets + py_test_targets,
        )
