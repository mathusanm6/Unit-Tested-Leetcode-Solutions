"""Test cases for the longestCommonPrefix function."""

import sys
from pathlib import Path

import pytest

# Add the root directory to Python path
root_dir = Path(__file__).parent.parent.parent
sys.path.insert(0, str(root_dir))

from longest_common_prefix import longestCommonPrefix


@pytest.mark.parametrize(
    "strs, expected",
    [
        (["flower", "flow", "flight"], "fl"),  # Common prefix exists
        (["dog", "racecar", "car"], ""),  # No common prefix
        (["", "b"], ""),  # Input contains empty string
        (["ab", "a"], "a"),  # Prefix is entire word
    ],
    ids=[
        "basic_example_1",
        "no_common_prefix",
        "empty_string_present",
        "prefix_is_entire_word",
    ],
)
def test_longest_common_prefix(strs: list[str], expected: str) -> None:
    assert longestCommonPrefix(strs) == expected
