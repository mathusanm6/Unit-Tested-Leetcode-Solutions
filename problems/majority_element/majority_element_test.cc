#include "majority_element.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct MajorityElementCase {
    std::string test_name;
    std::vector<int> nums;
    int expected;
};

using MajorityElementTest = ::testing::TestWithParam<MajorityElementCase>;

TEST_P(MajorityElementTest, TestCases) {
    const MajorityElementCase &testCase = GetParam();
    const int result = majorityElement(testCase.nums);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    MajorityElementTestCases, MajorityElementTest,
    ::testing::Values(
        MajorityElementCase{.test_name = "BasicExample1", .nums = {3, 2, 3}, .expected = 3},
        MajorityElementCase{
            .test_name = "BasicExample2", .nums = {2, 2, 1, 1, 1, 2, 2}, .expected = 2},
        MajorityElementCase{.test_name = "SingleElement", .nums = {1}, .expected = 1},
        MajorityElementCase{.test_name = "AllElementsSame", .nums = {5, 5, 5, 5}, .expected = 5},
        MajorityElementCase{
            .test_name = "NegativeNumbers", .nums = {-1, -1, 2, -1, 3}, .expected = -1},
        MajorityElementCase{.test_name = "MajorityAtStart", .nums = {4, 4, 4, 1, 2}, .expected = 4},
        MajorityElementCase{.test_name = "MajorityAtEnd", .nums = {1, 2, 4, 4, 4}, .expected = 4}),
    [](const ::testing::TestParamInfo<MajorityElementCase> &info) { return info.param.test_name; });
