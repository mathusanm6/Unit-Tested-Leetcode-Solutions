#include "two_sum_ii_input_array_is_sorted.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct TwoSumIiInputArrayIsSortedCase {
    std::string test_name;
    std::vector<int> numbers;
    int target;
    std::vector<int> expected;
};

using TwoSumIiInputArrayIsSortedTest = ::testing::TestWithParam<TwoSumIiInputArrayIsSortedCase>;

TEST_P(TwoSumIiInputArrayIsSortedTest, TestCases) {
    const TwoSumIiInputArrayIsSortedCase& testCase = GetParam();
    const std::vector<int> result = twoSum(testCase.numbers, testCase.target);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    TwoSumIiInputArrayIsSortedTestCases, TwoSumIiInputArrayIsSortedTest,
    ::testing::Values(
        TwoSumIiInputArrayIsSortedCase{
            .test_name = "Example1", .numbers = {2, 7, 11, 15}, .target = 9, .expected = {1, 2}},
        TwoSumIiInputArrayIsSortedCase{
            .test_name = "Example2", .numbers = {2, 3, 4}, .target = 6, .expected = {1, 3}},
        TwoSumIiInputArrayIsSortedCase{
            .test_name = "Example3", .numbers = {-1, 0}, .target = -1, .expected = {1, 2}},
        TwoSumIiInputArrayIsSortedCase{.test_name = "WithDuplicates",
                                       .numbers = {0, 0, 3, 4},
                                       .target = 0,
                                       .expected = {1, 2}}),
    [](const ::testing::TestParamInfo<TwoSumIiInputArrayIsSortedCase>& info) {
        return info.param.test_name;
    });
