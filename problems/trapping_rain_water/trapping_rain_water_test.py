"""Test cases for the trap function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "trapping_rain_water_two_pointers"
)
_solution_mod = importlib.import_module(_module_name)
trap = _solution_mod.trap


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
def test_trap(height: list[int], expected: int) -> None:
    assert trap(height) == expected
