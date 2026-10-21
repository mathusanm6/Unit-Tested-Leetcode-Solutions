def lengthOfLastWord(s: str) -> int:
    i = len(s) - 1
    res = 0

    # Skip trailing spaces
    while i >= 0 and s[i] == " ":
        i -= 1

    # Count characters of the last word
    while i >= 0 and s[i] != " ":
        res += 1
        i -= 1
    return res
