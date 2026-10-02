"""Test cases for the isPalindrome function."""

import pytest
from valid_palindrome import isPalindrome


@pytest.mark.parametrize(
    "s, expected",
    [
        (
            "A man, a plan, a canal: Panama",
            True,
        ),  # Classic palindrome with spaces and punctuation
        ("race a car", False),  # Not a palindrome
        ("", True),  # Empty string
        ("a", True),  # Single character
        ("Aa", True),  # Case insensitive palindrome
        ("ab", False),  # Simple two character non-palindrome
        ("aa", True),  # Simple two character palindrome
        ("racecar", True),  # Simple palindrome
        ("hello", False),  # Simple non-palindrome
        ("A Santa at NASA", True),  # Palindrome with spaces
        ("Was it a car or a cat I saw?", True),  # Palindrome with punctuation
        ("No 'x' in Nixon", True),  # Palindrome with apostrophe
        ("Madam, I'm Adam", True),  # Palindrome with comma and apostrophe
        ("never odd or even", True),  # Palindrome with spaces
        ("nope", False),  # Simple non-palindrome
        ("0P", False),  # Mixed alphanumeric non-palindrome
        ("A man, a plan, a canal: Panama!", True),  # With exclamation
        ("race a E-car", True),  # With hyphen and mixed case
        ("Able was I ere I saw Elba", True),  # Historical palindrome
        ("12321", True),  # Numeric palindrome
        ("12345", False),  # Numeric non-palindrome
        ("a1b2c3c2b1a", True),  # Alphanumeric palindrome
        ("1a2b3c3c2b1a", False),  # Alphanumeric non-palindrome
        (".,!@#$%^&*()", True),
        # Only special characters (empty after cleaning)
        ("a.,!@#$%^&*()a", True),  # Palindrome with special chars in middle
        ("Dammit, I'm mad!", True),  # Another classic palindrome
        ("Step on no pets", True),  # Word-based palindrome
        ("Was it a rat I saw?", True),  # Question mark palindrome
        ("Mr. Owl ate my metal worm", True),  # Complex palindrome
    ],
    ids=[
        "classic_panama",
        "race_car_false",
        "empty_string",
        "single_char",
        "case_insensitive",
        "two_char_false",
        "two_char_true",
        "simple_palindrome",
        "simple_false",
        "santa_nasa",
        "car_cat_question",
        "nixon_apostrophe",
        "madam_adam",
        "never_odd_even",
        "nope_false",
        "mixed_alphanum_false",
        "panama_exclamation",
        "race_ecar_hyphen",
        "able_elba",
        "numeric_palindrome",
        "numeric_false",
        "alphanum_palindrome",
        "alphanum_false",
        "only_special_chars",
        "special_chars_middle",
        "dammit_mad",
        "step_pets",
        "rat_question",
        "owl_worm",
    ],
)
def test_is_palindrome(s, expected):
    assert isPalindrome(s) == expected
