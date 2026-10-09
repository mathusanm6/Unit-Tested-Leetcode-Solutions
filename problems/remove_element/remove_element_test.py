"""Test cases for the removeElement function."""

import pytest
from remove_element import removeElement


@pytest.mark.parametrize(
    "nums, val, expected_k, expected_nums",
    [
        ([3, 2, 2, 3], 3, 2, [2, 2]),  # Basic example 1
        ([0, 1, 2, 2, 3, 0, 4, 2], 2, 5, [0, 1, 3, 0, 4]),  # Basic example 2
        ([], 0, 0, []),  # Empty array
        ([2, 2, 2], 2, 0, []),  # All elements match val
        ([1, 2, 3], 4, 3, [1, 2, 3]),  # No elements match val
        ([1], 1, 0, []),  # Single element matching val
        ([1], 2, 1, [1]),  # Single element not matching val
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "empty_array",
        "all_elements_match",
        "no_elements_match",
        "single_element_match",
        "single_element_no_match",
    ],
)
def test_remove_element(nums, val, expected_k, expected_nums):
    k = removeElement(nums, val)
    assert k == expected_k
    assert nums[:k] == expected_nums
