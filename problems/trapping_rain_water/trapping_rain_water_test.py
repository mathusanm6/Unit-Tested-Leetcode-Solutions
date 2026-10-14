"""Test cases for the trap function."""

import pytest
from trapping_rain_water import trap


@pytest.mark.parametrize(
    "height, expected",
    [
        ([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], 6),  # Basic example 1
        ([4, 2, 0, 3, 2, 5], 9),  # Basic example 2
        ([], 0),  # Empty array
        ([1], 0),  # Single element
        ([2, 1], 0),  # Two elements
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "empty",
        "single_element",
        "two_elements",
    ],
)
def test_trap(height, expected):
    assert trap(height) == expected
