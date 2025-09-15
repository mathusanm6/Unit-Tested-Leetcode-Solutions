#include "brace_expansion.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct BraceExpansionCase {
    const std::string test_name;
    const std::string input;
    const std::vector<std::string> expected;
};

using BraceExpansionTest = ::testing::TestWithParam<BraceExpansionCase>;

TEST_P(BraceExpansionTest, TestCases) {
    const BraceExpansionCase &testCase = GetParam();
    const auto result = braceExpansion(testCase.input);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(BraceExpansionTestCases, BraceExpansionTest,
                         ::testing::Values(
                             BraceExpansionCase{
                                 .test_name = "BasicCase",
                                 .input = "{a,b}c{d,e}f",
                                 .expected = {"acdf", "acef", "bcdf", "bcef"},
                             },
                             BraceExpansionCase{
                                 .test_name = "NoBraces",
                                 .input = "abcd",
                                 .expected = {"abcd"},
                             },
                             BraceExpansionCase{
                                 .test_name = "LeadingLiteralFollowedByBraces",
                                 .input = "k{a,b,c,d,e,f,g}",
                                 .expected = {"ka", "kb", "kc", "kd", "ke", "kf", "kg"},
                             }),
                         [](const testing::TestParamInfo<BraceExpansionCase> &info) {
                             return info.param.test_name;
                         });
