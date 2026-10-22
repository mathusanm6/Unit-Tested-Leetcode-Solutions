#include "3sum.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct ThreeSumCase {
    std::string test_name;
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
};

using ThreeSumTest = ::testing::TestWithParam<ThreeSumCase>;

TEST_P(ThreeSumTest, TestCases) {
    ThreeSumCase testCase = GetParam();
    const std::vector<std::vector<int>> result = threeSum(testCase.nums);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(ThreeSumTestCases, ThreeSumTest,
                         ::testing::Values(
                             ThreeSumCase{
                                 .test_name = "Example1",
                                 .nums = {-1, 0, 1, 2, -1, -4},
                                 .expected = {{-1, -1, 2}, {-1, 0, 1}},
                             },
                             ThreeSumCase{
                                 .test_name = "Example2",
                                 .nums = {0, 1, 1},
                                 .expected = {},
                             },
                             ThreeSumCase{
                                 .test_name = "Example3",
                                 .nums = {0, 0, 0},
                                 .expected = {{0, 0, 0}},
                             }),
                         [](const ::testing::TestParamInfo<ThreeSumCase>& info) {
                             return info.param.test_name;
                         });
