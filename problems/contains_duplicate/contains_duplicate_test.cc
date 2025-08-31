#include "contains_duplicate.h"

#include <gtest/gtest.h>
#include <climits>
#include <string>
#include <vector>

struct ContainsDuplicateCase {
    std::string test_name;
    std::vector<int> nums;
    bool expected;
};

using ContainsDuplicateTest = ::testing::TestWithParam<ContainsDuplicateCase>;

TEST_P(ContainsDuplicateTest, TestCases) {
    const ContainsDuplicateCase &testCase = GetParam();
    std::vector<int> nums = testCase.nums;  // Copy since function takes non-const reference
    const bool result = containsDuplicate(nums);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    ContainsDuplicateTestCases, ContainsDuplicateTest,
    ::testing::Values(
        // Boundary conditions
        ContainsDuplicateCase{.test_name = "EmptyArray", .nums = {}, .expected = false},
        ContainsDuplicateCase{.test_name = "SingleElement", .nums = {42}, .expected = false},

        // Basic cases
        ContainsDuplicateCase{.test_name = "TwoUnique", .nums = {1, 2}, .expected = false},
        ContainsDuplicateCase{.test_name = "TwoDuplicate", .nums = {1, 1}, .expected = true},
        ContainsDuplicateCase{.test_name = "ThreeUnique", .nums = {1, 2, 3}, .expected = false},
        ContainsDuplicateCase{
            .test_name = "ThreeWithDuplicate", .nums = {1, 2, 1}, .expected = true},

        // Edge cases with special values
        ContainsDuplicateCase{.test_name = "ZeroDuplicate", .nums = {0, 1, 0}, .expected = true},
        ContainsDuplicateCase{
            .test_name = "NegativeDuplicate", .nums = {-1, -2, -1}, .expected = true},
        ContainsDuplicateCase{
            .test_name = "MinMaxValues", .nums = {INT_MIN, INT_MAX, INT_MIN}, .expected = true},

        // Position sensitivity
        ContainsDuplicateCase{
            .test_name = "DuplicateAtEnd", .nums = {1, 2, 3, 4, 5, 1}, .expected = true},
        ContainsDuplicateCase{
            .test_name = "DuplicateAtBoundaries", .nums = {5, 1, 2, 3, 4, 5}, .expected = true},

        // Performance edge cases
        ContainsDuplicateCase{.test_name = "LargeUniqueArray",
                              .nums =
                                  []() {
                                      std::vector<int> v;
                                      v.reserve(100);
                                      for (int i = 0; i < 100; ++i) {
                                          v.push_back(i);
                                      }
                                      return v;
                                  }(),
                              .expected = false},
        ContainsDuplicateCase{.test_name = "ManyDuplicates",
                              .nums =
                                  []() {
                                      std::vector<int> v(50, 1);
                                      v.push_back(2);
                                      return v;
                                  }(),
                              .expected = true},
        ContainsDuplicateCase{.test_name = "LargeArrayOneDuplicate",
                              .nums =
                                  []() {
                                      std::vector<int> v;
                                      v.reserve(5001);
                                      for (int i = 0; i < 5000; ++i) {
                                          v.push_back(i);
                                      }
                                      v.push_back(2500);  // Introduce a single duplicate
                                      return v;
                                  }(),
                              .expected = true}),
    [](const ::testing::TestParamInfo<ContainsDuplicateCase> &info) {
        return info.param.test_name;
    });