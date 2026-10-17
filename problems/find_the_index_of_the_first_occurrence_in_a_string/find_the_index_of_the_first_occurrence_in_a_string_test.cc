#include "find_the_index_of_the_first_occurrence_in_a_string.h"

#include <gtest/gtest.h>
#include <string>

struct FindTheIndexOfTheFirstOccurrenceInAStringCase {
    std::string test_name;
    std::string haystack;
    std::string needle;
    int expected;
};

using FindTheIndexOfTheFirstOccurrenceInAStringTest =
    ::testing::TestWithParam<FindTheIndexOfTheFirstOccurrenceInAStringCase>;

TEST_P(FindTheIndexOfTheFirstOccurrenceInAStringTest, TestCases) {
    FindTheIndexOfTheFirstOccurrenceInAStringCase testCase = GetParam();
    EXPECT_EQ(strStr(testCase.haystack, testCase.needle), testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheIndexOfTheFirstOccurrenceInAStringTestCases,
    FindTheIndexOfTheFirstOccurrenceInAStringTest,
    ::testing::Values(
        FindTheIndexOfTheFirstOccurrenceInAStringCase{
            .test_name = "BasicExample1",
            .haystack = "sadbutsad",
            .needle = "sad",
            .expected = 0,
        },
        FindTheIndexOfTheFirstOccurrenceInAStringCase{
            .test_name = "BasicExample2",
            .haystack = "leetcode",
            .needle = "leeto",
            .expected = -1,
        },
        FindTheIndexOfTheFirstOccurrenceInAStringCase{
            .test_name = "NeedleEqualsHaystack",
            .haystack = "a",
            .needle = "a",
            .expected = 0,
        },
        FindTheIndexOfTheFirstOccurrenceInAStringCase{
            .test_name = "NeedleLongerThanHaystack",
            .haystack = "a",
            .needle = "aaaa",
            .expected = -1,
        },
        FindTheIndexOfTheFirstOccurrenceInAStringCase{
            .test_name = "OccurrenceInMiddle",
            .haystack = "mississippi",
            .needle = "issip",
            .expected = 4,
        }),
    [](const ::testing::TestParamInfo<FindTheIndexOfTheFirstOccurrenceInAStringCase>& info) {
        return info.param.test_name;
    });
