"""Test cases for the longestCommonPrefix function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "longest_common_prefix_vertical_scanning"
)
_solution_mod = importlib.import_module(_module_name)
longestCommonPrefix = _solution_mod.longestCommonPrefix


@pytest.mark.parametrize(
    "strs, expected",
    [
        (["flower", "flow", "flight"], "fl"),  # Common prefix exists
        (["dog", "racecar", "car"], ""),  # No common prefix
        (["", "b"], ""),  # Input contains empty string
        (["ab", "a"], "a"),  # Prefix is entire word
        ([], ""),  # Empty input list
        (["alone"], "alone"),  # Single string
        (["same", "same", "same"], "same"),  # All strings identical
    ],
    ids=[
        "basic_example_1",
        "no_common_prefix",
        "empty_string_present",
        "prefix_is_entire_word",
        "empty_input",
        "single_string",
        "all_identical",
    ],
)
def test_longest_common_prefix(strs: list[str], expected: str) -> None:
    assert longestCommonPrefix(strs) == expected
