"""Test cases for the candy function."""

import pytest
from candy import candy


@pytest.mark.parametrize(
    "ratings, expected",
    [
        ([1, 0, 2], 5),  # Basic example 1
        ([1, 2, 2], 4),  # Basic example 2
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
    ],
)
def test_candy(ratings, expected):
    assert candy(ratings) == expected
