#include "evaluate_division.h"

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

namespace {
std::unordered_map<std::string, std::string> parent;
std::unordered_map<std::string, double> weight;

// NOLINTBEGIN(misc-no-recursion)
string find(const string& node, unordered_map<string, string>& parent,
            unordered_map<string, double>& weight) {
    if (parent[node] != node) {
        const string originalParent = parent[node];
        parent[node] = find(originalParent, parent, weight);
        weight[node] *= weight[originalParent];
    }
    return parent[node];
}
// NOLINTEND(misc-no-recursion)
}  // namespace

vector<double> evaluateDivision(const vector<vector<string>>& equations,
                                const vector<double>& values,
                                const vector<vector<string>>& queries) {
    // Clear previous state
    parent.clear();
    weight.clear();

    const size_t numEquations = equations.size();

    for (const auto& equation : equations) {
        parent[equation[0]] = equation[0];
        parent[equation[1]] = equation[1];
        weight[equation[0]] = 1.0;
        weight[equation[1]] = 1.0;
    }

    for (size_t i = 0; i < numEquations; ++i) {
        const vector<string>& equation = equations[i];
        const string& numerator = equation[0];
        const string& denominator = equation[1];

        const string parentNumerator = find(numerator, parent, weight);
        const string parentDenominator = find(denominator, parent, weight);

        if (parentNumerator == parentDenominator) {
            continue;
        }

        parent[parentNumerator] = parentDenominator;
        weight[parentNumerator] = values[i] * weight[denominator] / weight[numerator];
    }

    const size_t numQueries = queries.size();
    vector<double> results(numQueries);

    for (size_t i = 0; i < numQueries; ++i) {
        const vector<string>& query = queries[i];
        const string& numerator = query[0];
        const string& denominator = query[1];

        if (!parent.contains(numerator) || !parent.contains(denominator) ||
            find(numerator, parent, weight) != find(denominator, parent, weight)) {
            results[i] = -1.0;
        } else {
            results[i] = weight[numerator] / weight[denominator];
        }
    }

    return results;
}