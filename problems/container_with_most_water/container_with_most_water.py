def maxArea(height: list[int]) -> int:
    l, r = 0, len(height) - 1
    res = 0

    while l < r:
        hl, hr = height[l], height[r]
        res = max(res, min(hl, hr) * (r - l))

        if hl <= hr:
            l += 1
        else:
            r -= 1

    return res
