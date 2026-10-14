#include "trapping_rain_water.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct TrappingRainWaterCase {
    std::string test_name;
    std::vector<int> height;
    int expected;
};

using TrappingRainWaterTest = ::testing::TestWithParam<TrappingRainWaterCase>;

TEST_P(TrappingRainWaterTest, TestCases) {
    TrappingRainWaterCase testCase = GetParam();
    EXPECT_EQ(trap(testCase.height), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(TrappingRainWaterTestCases, TrappingRainWaterTest,
                         ::testing::Values(
                             TrappingRainWaterCase{
                                 .test_name = "BasicExample1",
                                 .height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
                                 .expected = 6,
                             },
                             TrappingRainWaterCase{
                                 .test_name = "BasicExample2",
                                 .height = {4, 2, 0, 3, 2, 5},
                                 .expected = 9,
                             },
                             TrappingRainWaterCase{
                                 .test_name = "Empty",
                                 .height = {},
                                 .expected = 0,
                             },
                             TrappingRainWaterCase{
                                 .test_name = "SingleElement",
                                 .height = {1},
                                 .expected = 0,
                             },
                             TrappingRainWaterCase{
                                 .test_name = "TwoElements",
                                 .height = {2, 1},
                                 .expected = 0,
                             }),
                         [](const ::testing::TestParamInfo<TrappingRainWaterCase>& info) {
                             return info.param.test_name;
                         });
