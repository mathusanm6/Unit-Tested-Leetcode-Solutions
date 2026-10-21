"""Test cases for the jump function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "jump_game_ii_dynamic_programming"
)
_solution_mod = importlib.import_module(_module_name)
jump = _solution_mod.jump


@pytest.mark.parametrize(
    "nums, expected",
    [
        ([2, 3, 1, 1, 4], 2),  # Jump from index 0 to 1, then to last index
        ([2, 3, 0, 1, 4], 2),  # Jump from index 0 to 1 avoiding zero, then to end
        ([0], 0),  # Single element already at the last index
    ],
    ids=[
        "example_1",
        "example_2",
        "single_element",
    ],
)
def test_jump(nums: list[int], expected: int) -> None:
    assert jump(nums) == expected
