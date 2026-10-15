"""Test cases for the lengthOfLastWord function."""

import pytest
from length_of_last_word import lengthOfLastWord


@pytest.mark.parametrize(
    "s, expected",
    [
        ("Hello World", 5),  # Basic example 1
        ("   fly me   to   the moon  ", 4),  # Multiple spaces and trailing spaces
        ("luffy is still joyboy", 6),  # Multiple words
    ],
    ids=[
        "basic_example_1",
        "with_trailing_and_multiple_spaces",
        "multiple_words",
    ],
)
def test_length_of_last_word(s: str, expected: int) -> None:
    assert lengthOfLastWord(s) == expected
