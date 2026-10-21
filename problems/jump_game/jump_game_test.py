"""Test cases for the canJump function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "jump_game_dynamic_programming"
)
_solution_mod = importlib.import_module(_module_name)
canJump = _solution_mod.canJump


@pytest.mark.parametrize(
    "nums, expected",
    [
        ([2, 3, 1, 1, 4], True),  # Reachable end
        ([3, 2, 1, 0, 4], False),  # Blocked at index 3
        ([0], True),  # Single element already at end
    ],
    ids=[
        "reachable_end",
        "blocked_at_zero",
        "single_element",
    ],
)
def test_canJump(nums, expected):
    assert canJump(nums) == expected
