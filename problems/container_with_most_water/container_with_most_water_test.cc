#include "container_with_most_water.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct ContainerWithMostWaterCase {
    std::string test_name;
    std::vector<int> height;
    int expected;
};

using ContainerWithMostWaterTest = ::testing::TestWithParam<ContainerWithMostWaterCase>;

TEST_P(ContainerWithMostWaterTest, TestCases) {
    const ContainerWithMostWaterCase& testCase = GetParam();
    const int result = maxArea(testCase.height);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    ContainerWithMostWaterTestCases, ContainerWithMostWaterTest,
    ::testing::Values(
        ContainerWithMostWaterCase{
            .test_name = "Example1", .height = {1, 8, 6, 2, 5, 4, 8, 3, 7}, .expected = 49},
        ContainerWithMostWaterCase{.test_name = "Example2", .height = {1, 1}, .expected = 1}),
    [](const ::testing::TestParamInfo<ContainerWithMostWaterCase>& info) {
        return info.param.test_name;
    });
