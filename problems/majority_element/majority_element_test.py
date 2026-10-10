"""Test cases for the majorityElement function."""

import pytest
from majority_element import majorityElement


@pytest.mark.parametrize(
    "nums, expected",
    [
        ([3, 2, 3], 3),  # Basic example 1
        ([2, 2, 1, 1, 1, 2, 2], 2),  # Basic example 2
        ([1], 1),  # Single element
        ([5, 5, 5, 5], 5),  # All elements same
        ([-1, -1, 2, -1, 3], -1),  # Negative numbers
        ([4, 4, 4, 1, 2], 4),  # Majority at start
        ([1, 2, 4, 4, 4], 4),  # Majority at end
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_element",
        "all_elements_same",
        "negative_numbers",
        "majority_at_start",
        "majority_at_end",
    ],
)
def test_majority_element(nums: list[int], expected: int) -> None:
    assert majorityElement(nums) == expected
