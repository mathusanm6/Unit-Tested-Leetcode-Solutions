"""Test cases for the jump function."""

import pytest
from jump_game_ii import jump


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
def test_jump(nums, expected):
    assert jump(nums) == expected
