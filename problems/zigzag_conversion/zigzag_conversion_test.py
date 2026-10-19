"""Test cases for the convert function."""

import importlib
import os

import pytest

_module_name = os.environ.get(
    "LEETCODE_SOLUTION_MODULE", "zigzag_conversion_row_buckets"
)
_solution_mod = importlib.import_module(_module_name)
convert = _solution_mod.convert


@pytest.mark.parametrize(
    "s, num_rows, expected",
    [
        ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),  # Basic example 1
        ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),  # Basic example 2
        ("A", 1, "A"),  # Single character and single row
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_char_single_row",
    ],
)
def test_convert(s, num_rows, expected):
    assert convert(s, num_rows) == expected
