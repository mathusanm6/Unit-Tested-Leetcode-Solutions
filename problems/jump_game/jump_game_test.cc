#include "jump_game.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct JumpGameCase {
    std::string test_name;
    std::vector<int> nums;
    bool expected;
};

using JumpGameTest = ::testing::TestWithParam<JumpGameCase>;

TEST_P(JumpGameTest, TestCases) {
    JumpGameCase testCase = GetParam();
    EXPECT_EQ(canJump(testCase.nums), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(JumpGameTestCases, JumpGameTest,
                         ::testing::Values(
                             JumpGameCase{
                                 .test_name = "ReachableEnd",
                                 .nums = {2, 3, 1, 1, 4},
                                 .expected = true,
                             },
                             JumpGameCase{
                                 .test_name = "BlockedAtZero",
                                 .nums = {3, 2, 1, 0, 4},
                                 .expected = false,
                             },
                             JumpGameCase{
                                 .test_name = "SingleElement",
                                 .nums = {0},
                                 .expected = true,
                             }),
                         [](const ::testing::TestParamInfo<JumpGameCase> &info) {
                             return info.param.test_name;
                         });
