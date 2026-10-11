#include "best_time_to_buy_and_sell_stock_ii.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct BestTimeToBuyAndSellStockIICase {
    std::string test_name;
    std::vector<int> prices;
    int expected;
};

using BestTimeToBuyAndSellStockIITest = ::testing::TestWithParam<BestTimeToBuyAndSellStockIICase>;

TEST_P(BestTimeToBuyAndSellStockIITest, TestCases) {
    const BestTimeToBuyAndSellStockIICase &testCase = GetParam();
    const int result = maxProfit(testCase.prices);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    BestTimeToBuyAndSellStockIITestCases, BestTimeToBuyAndSellStockIITest,
    ::testing::Values(
        BestTimeToBuyAndSellStockIICase{
            .test_name = "BasicExample1", .prices = {7, 1, 5, 3, 6, 4}, .expected = 7},
        BestTimeToBuyAndSellStockIICase{
            .test_name = "BasicExample2", .prices = {1, 2, 3, 4, 5}, .expected = 4},
        BestTimeToBuyAndSellStockIICase{
            .test_name = "BasicExample3", .prices = {7, 6, 4, 3, 1}, .expected = 0},
        BestTimeToBuyAndSellStockIICase{.test_name = "SingleElement", .prices = {5}, .expected = 0},
        BestTimeToBuyAndSellStockIICase{
            .test_name = "TwoElementsProfit", .prices = {1, 5}, .expected = 4},
        BestTimeToBuyAndSellStockIICase{
            .test_name = "TwoElementsNoProfit", .prices = {5, 1}, .expected = 0},
        BestTimeToBuyAndSellStockIICase{
            .test_name = "AllSamePrices", .prices = {3, 3, 3, 3}, .expected = 0}),
    [](const ::testing::TestParamInfo<BestTimeToBuyAndSellStockIICase> &info) {
        return info.param.test_name;
    });
