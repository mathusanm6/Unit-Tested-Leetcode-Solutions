"""Test cases for the maxProfit function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "best_time_to_buy_and_sell_stock_greedy"
)
_solution_mod = importlib.import_module(_module_name)
maxProfit = _solution_mod.maxProfit


@pytest.mark.parametrize(
    "prices, expected",
    [
        ([7, 1, 5, 3, 6, 4], 5),  # Basic example 1
        ([7, 6, 4, 3, 1], 0),  # Basic example 2
        ([5], 0),  # Single element
        ([1, 5], 4),  # Two elements with profit
        ([5, 1], 0),  # Two elements with no profit
        ([3, 3, 3, 3], 0),  # All prices equal
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_element",
        "two_elements_profit",
        "two_elements_no_profit",
        "all_same_prices",
    ],
)
def test_max_profit(prices: list[int], expected: int) -> None:
    assert maxProfit(prices) == expected
