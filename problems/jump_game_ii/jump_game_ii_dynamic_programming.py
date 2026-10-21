def jump(nums: list[int]) -> int:
    n = len(nums)

    # dp[i] = minimum jumps needed from index i to reach the end
    dp = [float("inf")] * n
    dp[-1] = 0

    for i in range(n - 2, -1, -1):
        if nums[i] == 0:
            continue
        max_reach = min(i + nums[i], n - 1)
        # Find the minimum among reachable states
        dp[i] = 1 + min(dp[i + 1 : max_reach + 1])

    return dp[0]
