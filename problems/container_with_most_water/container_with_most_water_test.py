"""Test cases for the maxArea function."""

import pytest
from container_with_most_water import maxArea


@pytest.mark.parametrize(
    "height, expected",
    [
        ([1, 8, 6, 2, 5, 4, 8, 3, 7], 49),  # Example 1: basic case
        ([1, 1], 1),  # Example 2: minimum length array
    ],
    ids=[
        "example_1",
        "example_2",
    ],
)
def test_max_area(height: list[int], expected: int):
    assert maxArea(height) == expected
