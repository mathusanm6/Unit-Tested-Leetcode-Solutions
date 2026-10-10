"""Test cases for the removeDuplicates function."""

import pytest
from remove_duplicates_from_sorted_array_ii import removeDuplicates


@pytest.mark.parametrize(
    "nums, expected_k, expected_nums",
    [
        ([1, 1, 1, 2, 2, 3], 5, [1, 1, 2, 2, 3]),  # Basic example 1
        ([0, 0, 1, 1, 1, 1, 2, 3, 3], 7, [0, 0, 1, 1, 2, 3, 3]),  # Basic example 2
        ([], 0, []),  # Empty array
        ([1], 1, [1]),  # Single element
        ([1, 1, 1], 2, [1, 1]),  # All duplicates
        ([1, 2, 3], 3, [1, 2, 3]),  # Already unique
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "empty_array",
        "single_element",
        "all_duplicates",
        "already_unique",
    ],
)
def test_remove_duplicates(nums, expected_k, expected_nums):
    k = removeDuplicates(nums)
    assert k == expected_k
    assert nums[:k] == expected_nums
