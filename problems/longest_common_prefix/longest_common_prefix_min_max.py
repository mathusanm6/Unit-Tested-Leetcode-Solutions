def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ""

    s1, s2 = min(strs), max(strs)
    for i, ch in enumerate(s1):
        if i >= len(s2) or ch != s2[i]:
            return s1[:i]

    return s1
