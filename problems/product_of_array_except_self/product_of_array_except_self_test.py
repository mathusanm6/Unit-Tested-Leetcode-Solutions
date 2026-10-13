"""Test cases for the productExceptSelf function."""

import pytest
from product_of_array_except_self import productExceptSelf


@pytest.mark.parametrize(
    "nums, expected",
    [
        ([1, 2, 3, 4], [24, 12, 8, 6]),  # Basic example 1
        ([-1, 1, 0, -3, 3], [0, 0, 9, 0, 0]),  # Basic example 2 with zero
        ([2, 3], [3, 2]),  # Two elements
        ([0, 4, 0], [0, 0, 0]),  # Multiple zeros
        ([1, 1, 1, 1], [1, 1, 1, 1]),  # All ones
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "two_elements",
        "multiple_zeros",
        "all_ones",
    ],
)
def test_product_except_self(nums: list[int], expected: list[int]) -> None:
    assert productExceptSelf(nums) == expected
