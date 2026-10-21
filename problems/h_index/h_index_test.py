"""Test cases for the hIndex function."""

import importlib
import os

import pytest

_module_name = os.environ.get("LEETCODE_SOLUTION_MODULE", "h_index_sorting")
_solution_mod = importlib.import_module(_module_name)
hIndex = _solution_mod.hIndex


@pytest.mark.parametrize(
    "citations, expected",
    [
        ([3, 0, 6, 1, 5], 3),  # 3 papers with at least 3 citations each
        ([1, 3, 1], 1),  # 1 paper with at least 1 citation
        ([0], 0),  # Single paper with 0 citations
    ],
    ids=[
        "example_1",
        "example_2",
        "single_zero_citation",
    ],
)
def test_h_index(citations, expected):
    assert hIndex(citations) == expected
