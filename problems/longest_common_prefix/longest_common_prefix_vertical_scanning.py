def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ""

    first = strs[0]
    for i, ch in enumerate(first):
        for s in strs[1:]:
            if i == len(s) or s[i] != ch:
                return first[:i]

    return first
