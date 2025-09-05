"""Test cases for the group_anagrams function."""

import pytest

from group_anagrams import groupAnagrams


@pytest.mark.parametrize(
    "strs, expected",
    [
        (
            ["eat", "tea", "tan", "ate", "nat", "bat"],
            [["bat"], ["tan", "nat"], ["eat", "tea", "ate"]],
        ),  # Basic case
        ([""], [[""]]),  # Single empty string
        (["a"], [["a"]]),  # Single character
        (
            ["abc", "bca", "cab", "xyz", "zyx", "yxz"],
            [["abc", "bca", "cab"], ["xyz", "zyx", "yxz"]],
        ),  # Multiple anagram groups
        (
            ["listen", "silent", "enlist", "inlets", "google", "gogole"],
            [["listen", "silent", "enlist", "inlets"], ["google", "gogole"]],
        ),  # Longer strings
        (
            ["aabb", "abab", "bbaa", "baba", "abba"],
            [["aabb", "abab", "bbaa", "baba", "abba"]],
        ),  # All are anagrams
        (
            ["rat", "tar", "art", "star", "tars"],
            [["rat", "tar", "art"], ["star", "tars"]],
        ),  # Mixed lengths
        ([], []),  # Empty list
    ],
    ids=[
        "basic_case",
        "single_empty_string",
        "single_character",
        "multiple_anagram_groups",
        "longer_strings",
        "all_anagrams",
        "mixed_lengths",
        "empty_list",
    ],
)
def test_group_anagrams(strs, expected):
    result = groupAnagrams(strs)
    # Sort inner lists and the outer list for comparison
    result = [sorted(group) for group in result]
    result.sort()
    expected = [sorted(group) for group in expected]
    expected.sort()
    assert result == expected
