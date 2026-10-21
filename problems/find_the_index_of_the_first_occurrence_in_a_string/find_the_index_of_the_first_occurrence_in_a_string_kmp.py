def strStr(haystack: str, needle: str) -> int:
    if not needle:
        return 0

    # 1. Build Longest Prefix Suffix (LPS) array
    lps = [0] * len(needle)
    prev_lps, i = 0, 1
    while i < len(needle):
        if needle[i] == needle[prev_lps]:
            prev_lps += 1
            lps[i] = prev_lps
            i += 1
        elif prev_lps == 0:
            lps[i] = 0
            i += 1
        else:
            prev_lps = lps[prev_lps - 1]

    # 2. Match needle against haystack
    h_idx, n_idx = 0, 0
    while h_idx < len(haystack):
        if haystack[h_idx] == needle[n_idx]:
            h_idx += 1
            n_idx += 1
            if n_idx == len(needle):
                return h_idx - len(needle)
        else:
            if n_idx == 0:
                h_idx += 1
            else:
                n_idx = lps[n_idx - 1]

    return -1
