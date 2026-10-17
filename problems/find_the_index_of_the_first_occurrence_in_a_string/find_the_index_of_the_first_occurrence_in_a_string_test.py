"""Test cases for the strStr function."""

import pytest
from find_the_index_of_the_first_occurrence_in_a_string import strStr


@pytest.mark.parametrize(
    "haystack, needle, expected",
    [
        ("sadbutsad", "sad", 0),  # First occurrence at start
        ("leetcode", "leeto", -1),  # Needle not found
        ("a", "a", 0),  # Single character match
        ("a", "aaaa", -1),  # Needle longer than haystack
        ("mississippi", "issip", 4),  # Occurrence in middle
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "needle_equals_haystack",
        "needle_longer_than_haystack",
        "occurrence_in_middle",
    ],
)
def test_str_str(haystack: str, needle: str, expected: int) -> None:
    assert strStr(haystack, needle) == expected
