#include "rotate_array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct RotateArrayCase {
    std::string test_name;
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
};

using RotateArrayTest = ::testing::TestWithParam<RotateArrayCase>;

TEST_P(RotateArrayTest, TestCases) {
    RotateArrayCase testCase = GetParam();
    rotate(testCase.nums, testCase.k);
    EXPECT_EQ(testCase.nums, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    RotateArrayTestCases, RotateArrayTest,
    ::testing::Values(
        RotateArrayCase{.test_name = "BasicExample1",
                        .nums = {1, 2, 3, 4, 5, 6, 7},
                        .k = 3,
                        .expected = {5, 6, 7, 1, 2, 3, 4}},
        RotateArrayCase{.test_name = "BasicExample2",
                        .nums = {-1, -100, 3, 99},
                        .k = 2,
                        .expected = {3, 99, -1, -100}},
        RotateArrayCase{
            .test_name = "SingleElementLargeK", .nums = {1}, .k = 10000, .expected = {1}},
        RotateArrayCase{.test_name = "EmptyArray", .nums = {}, .k = 3, .expected = {}},
        RotateArrayCase{
            .test_name = "ZeroRotation", .nums = {1, 2, 3}, .k = 0, .expected = {1, 2, 3}}),
    [](const ::testing::TestParamInfo<RotateArrayCase>& info) { return info.param.test_name; });
