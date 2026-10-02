"""Test cases for the merge_sorted_array function."""

import pytest
from merge_sorted_array import merge


@pytest.mark.parametrize(
    "nums1, m, nums2, n, expected",
    [
        ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),  # Basic case
        ([], 0, [], 0, []),  # Empty arrays
        ([0], 0, [1], 1, [1]),  # num1 is empty
        ([1], 1, [], 0, [1]),  # num2 is empty
    ],
    ids=[
        "basic_case",
        "both_empty",
        "num1_empty",
        "num2_empty",
    ],
)
def test_merge(nums1, m, nums2, n, expected):
    merge(nums1, m, nums2, n)
    assert nums1 == expected
