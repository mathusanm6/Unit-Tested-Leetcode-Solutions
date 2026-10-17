def strStr(haystack: str, needle: str) -> int:
    n, m = len(haystack), len(needle)
    if m == 0:
        return 0
    if n < m:
        return -1

    haystack_list = list(haystack)
    needle_list = list(needle)

    # Only iterate up to the last index where needle could fit
    for i in range(n - m + 1):
        if haystack_list[i : i + m] == needle_list:
            return i
    return -1
