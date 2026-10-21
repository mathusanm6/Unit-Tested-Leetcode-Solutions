#include "longest_common_prefix.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct LongestCommonPrefixCase {
    std::string test_name;
    std::vector<std::string> strs;
    std::string expected;
};

using LongestCommonPrefixTest = ::testing::TestWithParam<LongestCommonPrefixCase>;

TEST_P(LongestCommonPrefixTest, TestCases) {
    LongestCommonPrefixCase testCase = GetParam();
    EXPECT_EQ(longestCommonPrefix(testCase.strs), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    LongestCommonPrefixTestCases, LongestCommonPrefixTest,
    ::testing::Values(
        LongestCommonPrefixCase{
            .test_name = "BasicExample1", .strs = {"flower", "flow", "flight"}, .expected = "fl"},
        LongestCommonPrefixCase{
            .test_name = "NoCommonPrefix", .strs = {"dog", "racecar", "car"}, .expected = ""},
        LongestCommonPrefixCase{
            .test_name = "EmptyStringPresent", .strs = {"", "b"}, .expected = ""},
        LongestCommonPrefixCase{
            .test_name = "PrefixIsEntireWord", .strs = {"ab", "a"}, .expected = "a"},
        LongestCommonPrefixCase{.test_name = "EmptyInput", .strs = {}, .expected = ""},
        LongestCommonPrefixCase{
            .test_name = "SingleString", .strs = {"alone"}, .expected = "alone"},
        LongestCommonPrefixCase{
            .test_name = "AllIdentical", .strs = {"same", "same", "same"}, .expected = "same"}),
    [](const ::testing::TestParamInfo<LongestCommonPrefixCase>& info) {
        return info.param.test_name;
    });
