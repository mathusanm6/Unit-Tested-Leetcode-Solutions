"""Test cases for the isSubsequence function."""

import pytest
from is_subsequence import isSubsequence


@pytest.mark.parametrize(
    "s, t, expected",
    [
        ("abc", "ahbgdc", True),  # Basic example 1: characters appear in order
        ("axc", "ahbgdc", False),  # Basic example 2: character 'x' not in t
        ("b", "abc", True),  # Single character match
        ("", "ahbgdc", True),  # Empty string s is always a subsequence
        ("", "", True),  # Both strings empty
        ("aaaa", "aa", False),  # s longer than t
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_character_match",
        "empty_s",
        "empty_both",
        "s_longer_than_t",
    ],
)
def test_is_subsequence(s: str, t: str, expected: bool) -> None:
    assert isSubsequence(s, t) == expected
