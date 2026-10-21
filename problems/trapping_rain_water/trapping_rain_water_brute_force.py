def trap(height: list[int]) -> int:
    if not height:
        return 0

    n = len(height)
    water = 0
    for i in range(n):
        left_max = max(height[: i + 1])  # O(n) re-computation
        right_max = max(height[i:])  # O(n) re-computation
        water += min(left_max, right_max) - height[i]

    return water
