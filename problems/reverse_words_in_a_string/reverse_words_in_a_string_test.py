"""Test cases for the reverseWords function."""

import pytest
from reverse_words_in_a_string import reverseWords


@pytest.mark.parametrize(
    "s, expected",
    [
        ("the sky is blue", "blue is sky the"),  # Basic example
        ("  hello world  ", "world hello"),  # Leading and trailing spaces
        ("a good   example", "example good a"),  # Multiple spaces between words
    ],
    ids=[
        "basic_example",
        "leading_and_trailing_spaces",
        "multiple_spaces_between_words",
    ],
)
def test_reverse_words(s: str, expected: str) -> None:
    assert reverseWords(s) == expected
