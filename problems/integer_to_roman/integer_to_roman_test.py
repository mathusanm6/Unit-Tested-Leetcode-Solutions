"""Test cases for the intToRoman function."""

import pytest
from integer_to_roman import intToRoman


@pytest.mark.parametrize(
    "num, expected",
    [
        (3749, "MMMDCCXLIX"),  # Basic example 1
        (58, "LVIII"),  # Basic example 2
        (1994, "MCMXCIV"),  # Basic example 3
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "basic_example_3",
    ],
)
def test_int_to_roman(num, expected):
    assert intToRoman(num) == expected
