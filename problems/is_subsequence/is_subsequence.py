def isSubsequence(s: str, t: str) -> bool:
    if not s:
        return True
    if len(s) > len(t):
        return False

    i = 0
    n = len(s)

    for c in t:
        if c == s[i]:
            i += 1
            if i == n:
                return True

    return False
