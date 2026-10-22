"""Test cases for the twoSum function."""

import pytest
from two_sum_ii_input_array_is_sorted import twoSum


@pytest.mark.parametrize(
    "numbers, target, expected",
    [
        ([2, 7, 11, 15], 9, [1, 2]),  # Example 1: basic case with positive numbers
        ([2, 3, 4], 6, [1, 3]),  # Example 2: target formed by first and last elements
        ([-1, 0], -1, [1, 2]),  # Example 3: negative numbers
        ([0, 0, 3, 4], 0, [1, 2]),  # Duplicate elements forming target
    ],
    ids=[
        "example_1",
        "example_2",
        "example_3",
        "with_duplicates",
    ],
)
def test_two_sum(numbers: list[int], target: int, expected: list[int]):
    assert twoSum(numbers, target) == expected
