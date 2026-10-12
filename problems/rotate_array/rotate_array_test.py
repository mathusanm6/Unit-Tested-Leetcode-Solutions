"""Test cases for the rotate function."""

import pytest
from rotate_array import rotate


@pytest.mark.parametrize(
    "nums, k, expected",
    [
        ([1, 2, 3, 4, 5, 6, 7], 3, [5, 6, 7, 1, 2, 3, 4]),  # Basic example 1
        ([-1, -100, 3, 99], 2, [3, 99, -1, -100]),  # Basic example 2
        ([1], 10000, [1]),  # Single element with large k
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_element_large_k",
    ],
)
def test_rotate(nums, k, expected):
    rotate(nums, k)
    assert nums == expected
