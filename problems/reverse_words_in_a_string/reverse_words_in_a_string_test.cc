#include "reverse_words_in_a_string.h"

#include <gtest/gtest.h>
#include <string>

struct ReverseWordsInAStringCase {
    std::string test_name;
    std::string s;
    std::string expected;
};

using ReverseWordsInAStringTest = ::testing::TestWithParam<ReverseWordsInAStringCase>;

TEST_P(ReverseWordsInAStringTest, TestCases) {
    const ReverseWordsInAStringCase& testCase = GetParam();
    const std::string result = reverseWords(testCase.s);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    ReverseWordsInAStringTestCases, ReverseWordsInAStringTest,
    ::testing::Values(ReverseWordsInAStringCase{.test_name = "BasicExample",
                                                .s = "the sky is blue",
                                                .expected = "blue is sky the"},
                      ReverseWordsInAStringCase{.test_name = "LeadingAndTrailingSpaces",
                                                .s = "  hello world  ",
                                                .expected = "world hello"},
                      ReverseWordsInAStringCase{.test_name = "MultipleSpacesBetweenWords",
                                                .s = "a good   example",
                                                .expected = "example good a"}),
    [](const ::testing::TestParamInfo<ReverseWordsInAStringCase>& info) {
        return info.param.test_name;
    });
