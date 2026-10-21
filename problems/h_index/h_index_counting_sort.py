def hIndex(citations: list[int]) -> int:
    n = len(citations)
    counts = [0] * (n + 1)

    for citation in citations:
        counts[min(citation, n)] += 1

    total = 0
    for citation_count in range(n, -1, -1):
        total += counts[citation_count]
        if total >= citation_count:
            return citation_count
    return 0
