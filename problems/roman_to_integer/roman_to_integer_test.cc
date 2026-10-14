#include "roman_to_integer.h"

#include <gtest/gtest.h>
#include <string>

struct RomanToIntegerCase {
    std::string test_name;
    std::string s;
    int expected;
};

using RomanToIntegerTest = ::testing::TestWithParam<RomanToIntegerCase>;

TEST_P(RomanToIntegerTest, TestCases) {
    const RomanToIntegerCase &testCase = GetParam();
    const int result = romanToInt(testCase.s);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    RomanToIntegerTestCases, RomanToIntegerTest,
    ::testing::Values(
        RomanToIntegerCase{.test_name = "BasicExample1", .s = "III", .expected = 3},
        RomanToIntegerCase{.test_name = "BasicExample2", .s = "LVIII", .expected = 58},
        RomanToIntegerCase{.test_name = "BasicExample3", .s = "MCMXCIV", .expected = 1994},
        RomanToIntegerCase{.test_name = "SingleChar", .s = "I", .expected = 1},
        RomanToIntegerCase{.test_name = "SubtractionIv", .s = "IV", .expected = 4},
        RomanToIntegerCase{.test_name = "SubtractionIx", .s = "IX", .expected = 9},
        RomanToIntegerCase{.test_name = "SubtractionXl", .s = "XL", .expected = 40},
        RomanToIntegerCase{.test_name = "SubtractionXc", .s = "XC", .expected = 90},
        RomanToIntegerCase{.test_name = "SubtractionCd", .s = "CD", .expected = 400},
        RomanToIntegerCase{.test_name = "SubtractionCm", .s = "CM", .expected = 900},
        RomanToIntegerCase{.test_name = "MaxValue", .s = "MMMCMXCIX", .expected = 3999}),
    [](const ::testing::TestParamInfo<RomanToIntegerCase> &info) { return info.param.test_name; });
