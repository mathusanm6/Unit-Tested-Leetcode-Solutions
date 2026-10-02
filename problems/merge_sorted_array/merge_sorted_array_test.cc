#include "merge_sorted_array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct MergeSortedArrayCase {
    std::string test_name;
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
};

using MergeSortedArrayTest = ::testing::TestWithParam<MergeSortedArrayCase>;

TEST_P(MergeSortedArrayTest, TestCases) {
    MergeSortedArrayCase testCase = GetParam();
    merge(testCase.nums1, testCase.m, testCase.nums2, testCase.n);
    EXPECT_EQ(testCase.nums1, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    MergeSortedArrayTestCases, MergeSortedArrayTest,
    ::testing::Values(
        MergeSortedArrayCase{.test_name = "basic_example",
                             .nums1 = {1, 2, 3, 0, 0, 0},
                             .m = 3,
                             .nums2 = {2, 5, 6},
                             .n = 3,
                             .expected = {1, 2, 2, 3, 5, 6}},
        MergeSortedArrayCase{
            .test_name = "both_empty", .nums1 = {}, .m = 0, .nums2 = {}, .n = 0, .expected = {}},
        MergeSortedArrayCase{.test_name = "nums1_empty",
                             .nums1 = {0},
                             .m = 0,
                             .nums2 = {1},
                             .n = 1,
                             .expected = {1}},
        MergeSortedArrayCase{.test_name = "nums2_empty",
                             .nums1 = {1},
                             .m = 1,
                             .nums2 = {},
                             .n = 0,
                             .expected = {1}}),
    [](const testing::TestParamInfo<MergeSortedArrayCase> &info) { return info.param.test_name; });
