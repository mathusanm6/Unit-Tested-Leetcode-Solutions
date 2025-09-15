#include "calculate_amount_paid_in_taxes.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct CalculateAmountPaidInTaxesCase {
    std::string test_name;
    const std::vector<std::vector<int>> brackets;
    const int income;
    const double expected;
};

using CalculateAmountPaidInTaxesTest = ::testing::TestWithParam<CalculateAmountPaidInTaxesCase>;

TEST_P(CalculateAmountPaidInTaxesTest, TestCases) {
    const CalculateAmountPaidInTaxesCase& testCase = GetParam();
    const auto result = calculateAmountPaidInTaxes(testCase.brackets, testCase.income);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    CalculateAmountPaidInTaxesTestCases, CalculateAmountPaidInTaxesTest,
    ::testing::Values(CalculateAmountPaidInTaxesCase{.test_name = "Example1",
                                                     .brackets = {{3, 50}, {7, 10}, {12, 25}},
                                                     .income = 10,
                                                     .expected = 2.65000},
                      CalculateAmountPaidInTaxesCase{.test_name = "Example2",
                                                     .brackets = {{1, 0}, {4, 25}, {5, 50}},
                                                     .income = 2,
                                                     .expected = 0.25000},
                      CalculateAmountPaidInTaxesCase{.test_name = "Example3",
                                                     .brackets = {{2, 50}},
                                                     .income = 0,
                                                     .expected = 0.00000}),
    [](const testing::TestParamInfo<CalculateAmountPaidInTaxesCase>& info) {
        return info.param.test_name;
    });
