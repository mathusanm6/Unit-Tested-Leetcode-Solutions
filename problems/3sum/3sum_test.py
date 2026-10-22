"""Test cases for the threeSum function."""

import importlib

import pytest

_solution_mod = importlib.import_module("3sum")
threeSum = _solution_mod.threeSum


@pytest.mark.parametrize(
    "nums, expected",
    [
        (
            [-1, 0, 1, 2, -1, -4],
            [[-1, -1, 2], [-1, 0, 1]],
        ),  # Example 1: basic case with multiple triplets
        ([0, 1, 1], []),  # Example 2: no triplets sum to zero
        ([0, 0, 0], [[0, 0, 0]]),  # Example 3: all elements are zero
    ],
    ids=[
        "example_1",
        "example_2",
        "example_3",
    ],
)
def test_three_sum(nums: list[int], expected: list[list[int]]):
    assert threeSum(nums) == expected
