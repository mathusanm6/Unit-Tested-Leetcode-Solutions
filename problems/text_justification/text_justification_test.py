"""Test cases for the fullJustify function."""

import pytest
from text_justification import fullJustify


@pytest.mark.parametrize(
    "words, max_width, expected",
    [
        (
            ["This", "is", "an", "example", "of", "text", "justification."],
            16,
            ["This    is    an", "example  of text", "justification.  "],
        ),  # Basic example with multiple spaces distributed
        (
            ["What", "must", "be", "acknowledgment", "shall", "be"],
            16,
            ["What   must   be", "acknowledgment  ", "shall be        "],
        ),  # Line with single word and uneven space distribution
        (
            [
                "Science",
                "is",
                "what",
                "we",
                "understand",
                "well",
                "enough",
                "to",
                "explain",
                "to",
                "a",
                "computer.",
                "Art",
                "is",
                "everything",
                "else",
                "we",
                "do",
            ],
            20,
            [
                "Science  is  what we",
                "understand      well",
                "enough to explain to",
                "a  computer.  Art is",
                "everything  else  we",
                "do                  ",
            ],
        ),  # Longer text justification
    ],
    ids=[
        "basic_example_1",
        "single_word_on_line",
        "longer_text",
    ],
)
def test_full_justify(words, max_width, expected):
    assert fullJustify(words, max_width) == expected
