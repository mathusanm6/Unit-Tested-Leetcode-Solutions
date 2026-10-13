#include "candy.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct CandyCase {
    std::string test_name;
    std::vector<int> ratings;
    int expected;
};

using CandyTest = ::testing::TestWithParam<CandyCase>;

TEST_P(CandyTest, TestCases) {
    CandyCase testCase = GetParam();
    EXPECT_EQ(candy(testCase.ratings), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(CandyTestCases, CandyTest,
                         ::testing::Values(
                             CandyCase{
                                 .test_name = "BasicExample1",
                                 .ratings = {1, 0, 2},
                                 .expected = 5,
                             },
                             CandyCase{
                                 .test_name = "BasicExample2",
                                 .ratings = {1, 2, 2},
                                 .expected = 4,
                             }),
                         [](const ::testing::TestParamInfo<CandyCase> &info) {
                             return info.param.test_name;
                         });
