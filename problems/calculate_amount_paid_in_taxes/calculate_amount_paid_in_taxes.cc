#include "calculate_amount_paid_in_taxes.h"

#include <algorithm>
#include <vector>

using std::min;
using std::vector;

double calculateAmountPaidInTaxes(const vector<vector<int>>& brackets, const int income) {
    double totalTax = 0.0;

    int incomeRemaining = income;
    int previousUpperLimit = 0;

    for (const auto& bracket : brackets) {
        const int upperLimit = bracket[0];
        const int ratePercent = bracket[1];

        // If no income remains, break early.
        if (incomeRemaining <= 0) {
            return totalTax;
        }

        // Calculate the taxable amount in the current bracket.
        const int bracketSize = upperLimit - previousUpperLimit;
        const int taxableAmount = min(incomeRemaining, bracketSize);

        // Add the tax for this bracket.
        totalTax += taxableAmount * (ratePercent / 100.0);

        // Update remaining income and previous upper limit.
        incomeRemaining -= taxableAmount;
        previousUpperLimit = upperLimit;
    }

    return totalTax;
}