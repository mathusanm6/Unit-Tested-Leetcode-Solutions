#include "product_of_array_except_self.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct ProductOfArrayExceptSelfCase {
    std::string test_name;
    std::vector<int> nums;
    std::vector<int> expected;
};

using ProductOfArrayExceptSelfTest = ::testing::TestWithParam<ProductOfArrayExceptSelfCase>;

TEST_P(ProductOfArrayExceptSelfTest, TestCases) {
    const ProductOfArrayExceptSelfCase &testCase = GetParam();
    const std::vector<int> result = productExceptSelf(testCase.nums);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    ProductOfArrayExceptSelfTestCases, ProductOfArrayExceptSelfTest,
    ::testing::Values(ProductOfArrayExceptSelfCase{.test_name = "BasicExample1",
                                                   .nums = {1, 2, 3, 4},
                                                   .expected = {24, 12, 8, 6}},
                      ProductOfArrayExceptSelfCase{.test_name = "BasicExample2",
                                                   .nums = {-1, 1, 0, -3, 3},
                                                   .expected = {0, 0, 9, 0, 0}},
                      ProductOfArrayExceptSelfCase{
                          .test_name = "TwoElements", .nums = {2, 3}, .expected = {3, 2}},
                      ProductOfArrayExceptSelfCase{
                          .test_name = "MultipleZeros", .nums = {0, 4, 0}, .expected = {0, 0, 0}},
                      ProductOfArrayExceptSelfCase{
                          .test_name = "AllOnes", .nums = {1, 1, 1, 1}, .expected = {1, 1, 1, 1}}),
    [](const ::testing::TestParamInfo<ProductOfArrayExceptSelfCase> &info) {
        return info.param.test_name;
    });
