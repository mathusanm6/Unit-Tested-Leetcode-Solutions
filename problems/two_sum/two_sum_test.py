"""Test cases for the two_sum function."""

import pytest
from two_sum import twoSum


@pytest.mark.parametrize(
    "nums, target, expected",
    [
        ([2, 7, 11, 15], 9, [0, 1]),  # Basic case
        ([3, 2, 4], 6, [1, 2]),  # Middle elements
        ([3, 3], 6, [0, 1]),  # Duplicate elements
        ([-3, 1, 2, 3], 0, [0, 3]),  # Negative and positive mix
        ([0, 1], -1, [-1, -1]),  # Edge case: no solution
        ([1, 2, 3, 4, 5], 8, [2, 4]),  # Target at end
        ([5, 75, 25], 100, [1, 2]),  # Large numbers
        ([-1, -2, -3, -4, -5], -8, [2, 4]),  # All negative numbers
        ([0, 4, 3, 0], 0, [0, 3]),  # Duplicate zeros
        ([1, 1, 1, 1], 2, [0, 1]),  # Multiple duplicates
        ([1], 2, [-1, -1]),  # Single element, no solution
        ([2, 2], 4, [0, 1]),  # Two identical elements that sum to target
        ([1000, -1000], 0, [0, 1]),  # Large positive and negative
        ([1, 2, 3, 4, 5, 6], 11, [4, 5]),  # Larger array
        ([0, 0], 0, [0, 1]),  # Two zeros sum to zero
    ],
    ids=[
        "basic_case",
        "middle_elements",
        "duplicate_elements",
        "negative_positive_mix",
        "no_solution",
        "target_at_end",
        "large_numbers",
        "all_negative",
        "duplicate_zeros",
        "multiple_duplicates",
        "single_element",
        "identical_sum_to_target",
        "large_pos_neg",
        "larger_array",
        "two_zeros_sum_to_zero",
    ],
)
def test_two_sum(nums, target, expected):
    assert twoSum(nums, target) == expected
