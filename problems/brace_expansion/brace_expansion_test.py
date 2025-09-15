"""Test cases for the brace_expansion function."""

import pytest

from brace_expansion import braceExpansion


@pytest.mark.parametrize(
    "s, expected",
    [
        ("{a,b}c{d,e}f", ["acdf", "acef", "bcdf", "bcef"]),  # Basic Case
        ("abcd", ["abcd"]),  # No Braces
        (
            "k{a,b,c,d,e,f,g}",
            ["ka", "kb", "kc", "kd", "ke", "kf", "kg"],
        ),  # Leading Literal followed by Braces
    ],
    ids=[
        "Basic Case",
        "No Braces",
        "Leading Literal followed by Braces",
    ],
)
def test_brace_expansion(s, expected):
    assert braceExpansion(s) == expected
