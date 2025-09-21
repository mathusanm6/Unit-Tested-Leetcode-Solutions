"""Test cases for the evaluate_division function."""

import pytest

from evaluate_division import evaluateDivision


@pytest.mark.parametrize(
    "equations, values, queries, expected",
    [
        (
            [["a", "b"], ["b", "c"]],
            [2.0, 3.0],
            [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]],
            [6.00000, 0.50000, -1.00000, 1.00000, -1.00000],
        ),  # Example 1
        (
            [["a", "b"], ["b", "c"], ["bc", "cd"]],
            [1.5, 2.5, 5.0],
            [["a", "c"], ["c", "b"], ["bc", "cd"], ["cd", "bc"]],
            [3.75000, 0.40000, 5.00000, 0.20000],
        ),  # Example 2
        (
            [["a", "b"]],
            [0.5],
            [["a", "b"], ["b", "a"], ["a", "c"], ["x", "y"]],
            [0.50000, 2.00000, -1.00000, -1.00000],
        ),  # Example 3
    ],
    ids=["example_1", "example_2", "example_3"],
)
def test_evaluate_division(equations, values, queries, expected):
    assert evaluateDivision(equations, values, queries) == expected
