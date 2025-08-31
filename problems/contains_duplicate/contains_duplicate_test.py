"""Test cases for the contains_duplicate function."""

import pytest

from contains_duplicate import containsDuplicate


@pytest.mark.parametrize(
    "nums, expected",
    [
        # Boundary conditions
        ([], False),
        ([42], False),
        # Basic cases
        ([1, 2], False),
        ([1, 1], True),
        ([1, 2, 3], False),
        ([1, 2, 1], True),
        # Edge cases with special values
        ([0, 1, 0], True),
        ([-1, -2, -1], True),
        ([0, -0], True),  # 0 and -0 are equal
        # Position sensitivity
        ([1, 2, 3, 4, 5, 1], True),  # duplicate at end
        ([5, 1, 2, 3, 4, 5], True),  # duplicate at start/end
        # Performance edge cases
        (list(range(100)), False),  # no duplicates, larger array
        ([1] * 50 + [2], True),  # many duplicates
        (list(range(5000)) + [2500], True),  # large array with one duplicate
    ],
    ids=[
        "empty_array",
        "single_element",
        "two_unique",
        "two_duplicate",
        "three_unique",
        "three_with_duplicate",
        "zero_duplicate",
        "negative_duplicate",
        "zero_negative_zero",
        "duplicate_at_end",
        "duplicate_at_boundaries",
        "large_unique_array",
        "many_duplicates",
        "large_array_one_duplicate",
    ],
)
def test_contains_duplicate(nums, expected):
    """Test containsDuplicate with various input scenarios."""
    assert containsDuplicate(nums) == expected
