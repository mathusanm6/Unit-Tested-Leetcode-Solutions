from typing import List
from collections import defaultdict


def evaluateDivision(
    equations: List[List[str]], values: List[float], queries: List[List[str]]
) -> List[float]:
    def find(node: str) -> str:
        if parent[node] != node:
            original_parent = parent[node]
            parent[node] = find(original_parent)
            weight[node] *= weight[original_parent]
        return parent[node]

    weight = defaultdict(lambda: 1.0)
    parent = defaultdict(str)

    for numerator, denominator in equations:
        parent[numerator] = numerator
        parent[denominator] = denominator

    for (numerator, denominator), value in zip(equations, values):
        root_numerator = find(numerator)
        root_denominator = find(denominator)

        if root_numerator == root_denominator:
            continue

        parent[root_numerator] = root_denominator
        weight[root_numerator] = value * weight[denominator] / weight[numerator]

    results = []
    for numerator, denominator in queries:
        if (
            numerator not in parent
            or denominator not in parent
            or find(numerator) != find(denominator)
        ):
            results.append(-1.0)
        else:
            results.append(weight[numerator] / weight[denominator])

    return results
