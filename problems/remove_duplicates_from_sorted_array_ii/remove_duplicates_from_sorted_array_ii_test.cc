#include "remove_duplicates_from_sorted_array_ii.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct RemoveDuplicatesFromSortedArrayIiCase {
    std::string test_name;
    std::vector<int> nums;
    int expected_k;
    std::vector<int> expected_nums;
};

using RemoveDuplicatesFromSortedArrayIiTest =
    ::testing::TestWithParam<RemoveDuplicatesFromSortedArrayIiCase>;

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, TestCases) {
    RemoveDuplicatesFromSortedArrayIiCase testCase = GetParam();
    int k = removeDuplicates(testCase.nums);
    EXPECT_EQ(k, testCase.expected_k);
    std::vector<int> actual_nums(testCase.nums.begin(), testCase.nums.begin() + k);
    EXPECT_EQ(actual_nums, testCase.expected_nums);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicatesFromSortedArrayIiTestCases, RemoveDuplicatesFromSortedArrayIiTest,
    ::testing::Values(
        RemoveDuplicatesFromSortedArrayIiCase{.test_name = "BasicExample1",
                                              .nums = {1, 1, 1, 2, 2, 3},
                                              .expected_k = 5,
                                              .expected_nums = {1, 1, 2, 2, 3}},
        RemoveDuplicatesFromSortedArrayIiCase{.test_name = "BasicExample2",
                                              .nums = {0, 0, 1, 1, 1, 1, 2, 3, 3},
                                              .expected_k = 7,
                                              .expected_nums = {0, 0, 1, 1, 2, 3, 3}},
        RemoveDuplicatesFromSortedArrayIiCase{
            .test_name = "EmptyArray", .nums = {}, .expected_k = 0, .expected_nums = {}},
        RemoveDuplicatesFromSortedArrayIiCase{
            .test_name = "SingleElement", .nums = {1}, .expected_k = 1, .expected_nums = {1}},
        RemoveDuplicatesFromSortedArrayIiCase{.test_name = "AllDuplicates",
                                              .nums = {1, 1, 1},
                                              .expected_k = 2,
                                              .expected_nums = {1, 1}},
        RemoveDuplicatesFromSortedArrayIiCase{.test_name = "AlreadyUnique",
                                              .nums = {1, 2, 3},
                                              .expected_k = 3,
                                              .expected_nums = {1, 2, 3}}),
    [](const ::testing::TestParamInfo<RemoveDuplicatesFromSortedArrayIiCase> &info) {
        return info.param.test_name;
    });
