def maxProfit(prices: list[int]) -> int:
    min_price = float("inf")
    best_profit = 0
    for price in prices:
        best_profit = max(best_profit, price - min_price)
        min_price = min(min_price, price)
    return best_profit
