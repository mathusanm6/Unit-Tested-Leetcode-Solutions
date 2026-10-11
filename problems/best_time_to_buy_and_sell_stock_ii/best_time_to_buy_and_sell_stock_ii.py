def maxProfit(prices: list[int]) -> int:
    hold, sell = -prices[0], 0
    for price in prices:
        hold, sell = max(hold, sell - price), max(sell, hold + price)
    return sell
