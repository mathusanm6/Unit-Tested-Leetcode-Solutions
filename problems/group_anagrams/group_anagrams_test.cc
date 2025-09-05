#include "group_anagrams.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <ranges>  // NOLINT(misc-include-cleaner) needed for std::ranges::sort
#include <string>
#include <vector>

struct GroupAnagramsCase {
    std::string test_name;
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> expected;
};

using GroupAnagramsTest = ::testing::TestWithParam<GroupAnagramsCase>;

namespace {
// Helper function to sort and compare results
bool compareResults(std::vector<std::vector<std::string>> result,
                    std::vector<std::vector<std::string>> expected) {
    // Sort inner vectors and outer vector for comparison
    for (auto& group : result) {
        std::ranges::sort(group);
    }
    std::ranges::sort(result);

    for (auto& group : expected) {
        std::ranges::sort(group);
    }
    std::ranges::sort(expected);

    return result == expected;
}
}  // namespace

TEST_P(GroupAnagramsTest, TestCases) {
    const GroupAnagramsCase& testCase = GetParam();
    std::vector<std::string> input = testCase.strs;  // Make a copy since function might modify
    const std::vector<std::vector<std::string>> result = groupAnagrams(input);
    EXPECT_TRUE(compareResults(result, testCase.expected));
}

INSTANTIATE_TEST_SUITE_P(
    GroupAnagramsTestCases, GroupAnagramsTest,
    ::testing::Values(
        GroupAnagramsCase{.test_name = "BasicCase",
                          .strs = {"eat", "tea", "tan", "ate", "nat", "bat"},
                          .expected = {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}},
        GroupAnagramsCase{.test_name = "SingleEmptyString", .strs = {""}, .expected = {{""}}},
        GroupAnagramsCase{.test_name = "SingleCharacter", .strs = {"a"}, .expected = {{"a"}}},
        GroupAnagramsCase{.test_name = "MultipleAnagramGroups",
                          .strs = {"abc", "bca", "cab", "xyz", "zyx", "yxz"},
                          .expected = {{"abc", "bca", "cab"}, {"xyz", "zyx", "yxz"}}},
        GroupAnagramsCase{
            .test_name = "LongerStrings",
            .strs = {"listen", "silent", "enlist", "inlets", "google", "gogole"},
            .expected = {{"listen", "silent", "enlist", "inlets"}, {"google", "gogole"}}},
        GroupAnagramsCase{.test_name = "AllAnagrams",
                          .strs = {"aabb", "abab", "bbaa", "baba", "abba"},
                          .expected = {{"aabb", "abab", "bbaa", "baba", "abba"}}},
        GroupAnagramsCase{.test_name = "MixedLengths",
                          .strs = {"rat", "tar", "art", "star", "tars"},
                          .expected = {{"rat", "tar", "art"}, {"star", "tars"}}},
        GroupAnagramsCase{.test_name = "EmptyList", .strs = {}, .expected = {}}),
    [](const ::testing::TestParamInfo<GroupAnagramsCase>& info) { return info.param.test_name; });