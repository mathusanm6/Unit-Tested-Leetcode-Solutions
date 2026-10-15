#include "length_of_last_word.h"

#include <gtest/gtest.h>
#include <string>

struct LengthOfLastWordCase {
    std::string test_name;
    std::string s;
    int expected;
};

using LengthOfLastWordTest = ::testing::TestWithParam<LengthOfLastWordCase>;

TEST_P(LengthOfLastWordTest, TestCases) {
    const LengthOfLastWordCase& testCase = GetParam();
    const int result = lengthOfLastWord(testCase.s);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    LengthOfLastWordTestCases, LengthOfLastWordTest,
    ::testing::Values(
        LengthOfLastWordCase{.test_name = "BasicExample1", .s = "Hello World", .expected = 5},
        LengthOfLastWordCase{.test_name = "WithTrailingAndMultipleSpaces",
                             .s = "   fly me   to   the moon  ",
                             .expected = 4},
        LengthOfLastWordCase{
            .test_name = "MultipleWords", .s = "luffy is still joyboy", .expected = 6}),
    [](const ::testing::TestParamInfo<LengthOfLastWordCase>& info) {
        return info.param.test_name;
    });
