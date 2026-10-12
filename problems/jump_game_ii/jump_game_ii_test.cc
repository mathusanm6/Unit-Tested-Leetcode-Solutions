#include "jump_game_ii.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct JumpGameIICase {
    std::string test_name;
    std::vector<int> nums;
    int expected;
};

using JumpGameIITest = ::testing::TestWithParam<JumpGameIICase>;

TEST_P(JumpGameIITest, TestCases) {
    JumpGameIICase testCase = GetParam();
    EXPECT_EQ(jump(testCase.nums), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(JumpGameIITestCases, JumpGameIITest,
                         ::testing::Values(
                             JumpGameIICase{
                                 .test_name = "Example1",
                                 .nums = {2, 3, 1, 1, 4},
                                 .expected = 2,
                             },
                             JumpGameIICase{
                                 .test_name = "Example2",
                                 .nums = {2, 3, 0, 1, 4},
                                 .expected = 2,
                             },
                             JumpGameIICase{
                                 .test_name = "SingleElement",
                                 .nums = {0},
                                 .expected = 0,
                             }),
                         [](const ::testing::TestParamInfo<JumpGameIICase> &info) {
                             return info.param.test_name;
                         });
