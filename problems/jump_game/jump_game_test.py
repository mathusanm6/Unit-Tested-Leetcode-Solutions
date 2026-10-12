"""Test cases for the canJump function."""

import pytest
from jump_game import canJump


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
