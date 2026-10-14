#include "integer_to_roman.h"

#include <gtest/gtest.h>
#include <string>

struct IntegerToRomanCase {
    std::string test_name;
    int num;
    std::string expected;
};

using IntegerToRomanTest = ::testing::TestWithParam<IntegerToRomanCase>;

TEST_P(IntegerToRomanTest, TestCases) {
    const IntegerToRomanCase &testCase = GetParam();
    const std::string result = intToRoman(testCase.num);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    IntegerToRomanTestCases, IntegerToRomanTest,
    ::testing::Values(
        IntegerToRomanCase{.test_name = "BasicExample1", .num = 3749, .expected = "MMMDCCXLIX"},
        IntegerToRomanCase{.test_name = "BasicExample2", .num = 58, .expected = "LVIII"},
        IntegerToRomanCase{.test_name = "BasicExample3", .num = 1994, .expected = "MCMXCIV"}),
    [](const ::testing::TestParamInfo<IntegerToRomanCase> &info) { return info.param.test_name; });
