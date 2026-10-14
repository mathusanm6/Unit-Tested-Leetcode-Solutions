def romanToInt(s: str) -> int:
    val = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }
    n = len(s)
    res = 0
    for i in range(n):
        if i + 1 < n and val[s[i]] < val[s[i + 1]]:
            res -= val[s[i]]
        else:
            res += val[s[i]]
    return res
