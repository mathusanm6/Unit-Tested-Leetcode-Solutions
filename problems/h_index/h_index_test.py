"""Test cases for the hIndex function."""

import pytest
from h_index import hIndex


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
