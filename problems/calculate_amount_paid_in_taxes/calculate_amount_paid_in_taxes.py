from typing import List


def calculateAmountPaidInTaxes(brackets: List[List[int]], income: int) -> float:
    total_tax = 0.0

    income_remaining = income
    previous_upper_limit = 0

    for upper_limit, rate_percent in brackets:
        # If no income remains, break early.
        if income_remaining <= 0:
            return total_tax

        # Calculate the taxable amount in the current bracket.
        bracket_size = upper_limit - previous_upper_limit
        taxable_amount = min(income_remaining, bracket_size)

        # Add the tax for this bracket.
        total_tax += taxable_amount * (rate_percent / 100.0)

        # Update remaining income and previous upper limit.
        income_remaining -= taxable_amount
        previous_upper_limit = upper_limit

    return total_tax
