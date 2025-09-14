"""Test cases for the calculate_amount_paid_in_taxes function."""

import pytest

from calculate_amount_paid_in_taxes import calculateAmountPaidInTaxes


@pytest.mark.parametrize(
    "brackets, income, expected",
    [
        ([[3, 50], [7, 10], [12, 25]], 10, 2.65000),
        ([[1, 0], [4, 25], [5, 50]], 2, 0.25000),
        ([[2, 50]], 0, 0.00000),
    ],
    ids=[
        "example1",
        "example2",
        "example3",
    ],
)
def test_calculate_amount_paid_in_taxes(brackets, income, expected):
    assert calculateAmountPaidInTaxes(brackets, income) == expected
