#include "remove_element.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct RemoveElementCase {
    std::string test_name;
    std::vector<int> nums;
    int val;
    int expected_k;
    std::vector<int> expected_nums;
};

using RemoveElementTest = ::testing::TestWithParam<RemoveElementCase>;

TEST_P(RemoveElementTest, TestCases) {
    RemoveElementCase testCase = GetParam();
    int k = removeElement(testCase.nums, testCase.val);
    EXPECT_EQ(k, testCase.expected_k);
    std::vector<int> actual_nums(testCase.nums.begin(), testCase.nums.begin() + k);
    EXPECT_EQ(actual_nums, testCase.expected_nums);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveElementTestCases, RemoveElementTest,
    ::testing::Values(
        RemoveElementCase{.test_name = "BasicExample1",
                          .nums = {3, 2, 2, 3},
                          .val = 3,
                          .expected_k = 2,
                          .expected_nums = {2, 2}},
        RemoveElementCase{.test_name = "BasicExample2",
                          .nums = {0, 1, 2, 2, 3, 0, 4, 2},
                          .val = 2,
                          .expected_k = 5,
                          .expected_nums = {0, 1, 3, 0, 4}},
        RemoveElementCase{.test_name = "EmptyArray",
                          .nums = {},
                          .val = 0,
                          .expected_k = 0,
                          .expected_nums = {}},
        RemoveElementCase{.test_name = "AllElementsMatch",
                          .nums = {2, 2, 2},
                          .val = 2,
                          .expected_k = 0,
                          .expected_nums = {}},
        RemoveElementCase{.test_name = "NoElementsMatch",
                          .nums = {1, 2, 3},
                          .val = 4,
                          .expected_k = 3,
                          .expected_nums = {1, 2, 3}},
        RemoveElementCase{.test_name = "SingleElementMatch",
                          .nums = {1},
                          .val = 1,
                          .expected_k = 0,
                          .expected_nums = {}},
        RemoveElementCase{.test_name = "SingleElementNoMatch",
                          .nums = {1},
                          .val = 2,
                          .expected_k = 1,
                          .expected_nums = {1}}),
    [](const ::testing::TestParamInfo<RemoveElementCase> &info) { return info.param.test_name; });
