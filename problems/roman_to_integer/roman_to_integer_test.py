"""Test cases for the romanToInt function."""

import pytest
from roman_to_integer import romanToInt


@pytest.mark.parametrize(
    "s, expected",
    [
        ("III", 3),  # Basic example 1
        ("LVIII", 58),  # Basic example 2
        ("MCMXCIV", 1994),  # Basic example 3
        ("I", 1),  # Single character
        ("IV", 4),  # Subtraction rule IV
        ("IX", 9),  # Subtraction rule IX
        ("XL", 40),  # Subtraction rule XL
        ("XC", 90),  # Subtraction rule XC
        ("CD", 400),  # Subtraction rule CD
        ("CM", 900),  # Subtraction rule CM
        ("MMMCMXCIX", 3999),  # Maximum value
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "basic_example_3",
        "single_char",
        "subtraction_iv",
        "subtraction_ix",
        "subtraction_xl",
        "subtraction_xc",
        "subtraction_cd",
        "subtraction_cm",
        "max_value",
    ],
)
def test_roman_to_int(s, expected):
    assert romanToInt(s) == expected
