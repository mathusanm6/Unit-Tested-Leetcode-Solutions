def lengthOfLastWord(s: str) -> int:
    arr = s.split()
    if not arr:
        return 0
    return len(arr[-1])
