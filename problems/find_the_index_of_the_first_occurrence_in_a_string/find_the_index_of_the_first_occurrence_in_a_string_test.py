"""Test cases for the strStr function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE",
    "find_the_index_of_the_first_occurrence_in_a_string_brute_force",
)
_solution_mod = importlib.import_module(_module_name)
strStr = _solution_mod.strStr


@pytest.mark.parametrize(
    "haystack, needle, expected",
    [
        ("sadbutsad", "sad", 0),  # First occurrence at start
        ("leetcode", "leeto", -1),  # Needle not found
        ("a", "a", 0),  # Single character match
        ("a", "aaaa", -1),  # Needle longer than haystack
        ("mississippi", "issip", 4),  # Occurrence in middle
        ("hello", "", 0),  # Empty needle
        ("mississippi", "pi", 9),  # Repeated characters
        ("aabaaabaaac", "aabaaac", 4),  # Partial match backtrack
        ("ababcabcabababd", "ababd", 10),  # Repeating pattern
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "needle_equals_haystack",
        "needle_longer_than_haystack",
        "occurrence_in_middle",
        "empty_needle",
        "repeated_characters",
        "partial_match_backtrack",
        "repeating_pattern",
    ],
)
def test_str_str(haystack: str, needle: str, expected: int) -> None:
    assert strStr(haystack, needle) == expected
