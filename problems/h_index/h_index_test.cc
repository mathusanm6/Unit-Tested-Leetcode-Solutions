#include "h_index.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct HIndexCase {
    std::string test_name;
    std::vector<int> citations;
    int expected;
};

using HIndexTest = ::testing::TestWithParam<HIndexCase>;

TEST_P(HIndexTest, TestCases) {
    HIndexCase testCase = GetParam();
    EXPECT_EQ(hIndex(testCase.citations), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(HIndexTestCases, HIndexTest,
                         ::testing::Values(
                             HIndexCase{
                                 .test_name = "Example1",
                                 .citations = {3, 0, 6, 1, 5},
                                 .expected = 3,
                             },
                             HIndexCase{
                                 .test_name = "Example2",
                                 .citations = {1, 3, 1},
                                 .expected = 1,
                             },
                             HIndexCase{
                                 .test_name = "SingleZeroCitation",
                                 .citations = {0},
                                 .expected = 0,
                             }),
                         [](const ::testing::TestParamInfo<HIndexCase> &info) {
                             return info.param.test_name;
                         });
