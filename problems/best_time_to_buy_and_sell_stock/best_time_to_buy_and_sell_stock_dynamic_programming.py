def maxProfit(prices: list[int]) -> int:
    if not prices:
        return 0

    hold, sell = -prices[0], 0
    for price in prices[1:]:
        hold, sell = max(hold, -price), max(sell, hold + price)
    return sell
