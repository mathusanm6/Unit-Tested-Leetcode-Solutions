#include "is_subsequence.h"

#include <gtest/gtest.h>
#include <string>

struct IsSubsequenceCase {
    std::string test_name;
    std::string s;
    std::string t;
    bool expected;
};

using IsSubsequenceTest = ::testing::TestWithParam<IsSubsequenceCase>;

TEST_P(IsSubsequenceTest, TestCases) {
    const IsSubsequenceCase &testCase = GetParam();
    const bool result = isSubsequence(testCase.s, testCase.t);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(IsSubsequenceTestCases, IsSubsequenceTest,
                         ::testing::Values(
                             IsSubsequenceCase{
                                 .test_name = "BasicExample1",
                                 .s = "abc",
                                 .t = "ahbgdc",
                                 .expected = true,
                             },
                             IsSubsequenceCase{
                                 .test_name = "BasicExample2",
                                 .s = "axc",
                                 .t = "ahbgdc",
                                 .expected = false,
                             },
                             IsSubsequenceCase{
                                 .test_name = "SingleCharacterMatch",
                                 .s = "b",
                                 .t = "abc",
                                 .expected = true,
                             },
                             IsSubsequenceCase{
                                 .test_name = "EmptyS",
                                 .s = "",
                                 .t = "ahbgdc",
                                 .expected = true,
                             },
                             IsSubsequenceCase{
                                 .test_name = "EmptyBoth",
                                 .s = "",
                                 .t = "",
                                 .expected = true,
                             },
                             IsSubsequenceCase{
                                 .test_name = "SLongerThanT",
                                 .s = "aaaa",
                                 .t = "aa",
                                 .expected = false,
                             }),
                         [](const ::testing::TestParamInfo<IsSubsequenceCase> &info) {
                             return info.param.test_name;
                         });
