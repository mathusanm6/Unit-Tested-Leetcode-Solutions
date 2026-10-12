"""Test cases for the RandomizedSet class."""

import pytest
from insert_delete_getrandom_o1 import RandomizedSet


@pytest.mark.parametrize(
    "operations, inputs, expected",
    [
        (
            [
                "RandomizedSet",
                "insert",
                "remove",
                "insert",
                "getRandom",
                "remove",
                "insert",
                "getRandom",
            ],
            [[], [1], [2], [2], [], [1], [2], []],
            [None, True, False, True, 1, True, False, 2],
        ),  # LeetCode sample sequence
        (
            [
                "RandomizedSet",
                "insert",
                "getRandom",
                "remove",
                "remove",
                "insert",
                "getRandom",
            ],
            [[], [42], [], [42], [42], [42], []],
            [None, True, 42, True, False, True, 42],
        ),  # Single element insert, getRandom, remove and re-insert
        (
            ["RandomizedSet", "insert", "insert", "remove", "remove"],
            [[], [5], [5], [5], [5]],
            [None, True, False, True, False],
        ),  # Duplicate inserts and removes
        (
            [
                "RandomizedSet",
                "insert",
                "insert",
                "insert",
                "remove",
                "remove",
                "getRandom",
            ],
            [[], [10], [20], [30], [10], [30], []],
            [None, True, True, True, True, True, 20],
        ),  # Removing non-last element swaps with last element
        (
            ["RandomizedSet", "insert", "insert", "remove", "getRandom"],
            [[], [0], [-1], [0], []],
            [None, True, True, True, -1],
        ),  # Zero and negative values
    ],
    ids=[
        "basic_example",
        "single_element_operations",
        "duplicate_inserts_and_removes",
        "remove_first_element_swap",
        "negative_and_zero_values",
    ],
)
def test_randomized_set(
    operations: list[str],
    inputs: list[list[int]],
    expected: list[bool | int | None],
) -> None:
    randomized_set = None
    present: set[int] = set()

    for op, args, exp in zip(operations, inputs, expected, strict=True):
        if op == "RandomizedSet":
            randomized_set = RandomizedSet()
            present.clear()
            assert exp is None
        elif op == "insert":
            assert randomized_set is not None
            val = args[0]
            present.add(val)
            assert randomized_set.insert(val) == exp
        elif op == "remove":
            assert randomized_set is not None
            val = args[0]
            present.discard(val)
            assert randomized_set.remove(val) == exp
        elif op == "getRandom":
            assert randomized_set is not None
            result = randomized_set.getRandom()
            assert result in present
            if len(present) == 1:
                assert result == exp
