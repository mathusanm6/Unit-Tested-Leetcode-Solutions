def maxProfit(prices: list[int]) -> int:
    if not prices:
        return 0
    return sum(max(0, prices[i] - prices[i - 1]) for i in range(1, len(prices)))
