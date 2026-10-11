#include "best_time_to_buy_and_sell_stock.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct BestTimeToBuyAndSellStockCase {
    std::string test_name;
    std::vector<int> prices;
    int expected;
};

using BestTimeToBuyAndSellStockTest = ::testing::TestWithParam<BestTimeToBuyAndSellStockCase>;

TEST_P(BestTimeToBuyAndSellStockTest, TestCases) {
    const BestTimeToBuyAndSellStockCase &testCase = GetParam();
    const int result = maxProfit(testCase.prices);
    EXPECT_EQ(result, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    BestTimeToBuyAndSellStockTestCases, BestTimeToBuyAndSellStockTest,
    ::testing::Values(
        BestTimeToBuyAndSellStockCase{
            .test_name = "BasicExample1", .prices = {7, 1, 5, 3, 6, 4}, .expected = 5},
        BestTimeToBuyAndSellStockCase{
            .test_name = "BasicExample2", .prices = {7, 6, 4, 3, 1}, .expected = 0},
        BestTimeToBuyAndSellStockCase{.test_name = "SingleElement", .prices = {5}, .expected = 0},
        BestTimeToBuyAndSellStockCase{
            .test_name = "TwoElementsProfit", .prices = {1, 5}, .expected = 4},
        BestTimeToBuyAndSellStockCase{
            .test_name = "TwoElementsNoProfit", .prices = {5, 1}, .expected = 0},
        BestTimeToBuyAndSellStockCase{
            .test_name = "AllSamePrices", .prices = {3, 3, 3, 3}, .expected = 0}),
    [](const ::testing::TestParamInfo<BestTimeToBuyAndSellStockCase> &info) {
        return info.param.test_name;
    });
