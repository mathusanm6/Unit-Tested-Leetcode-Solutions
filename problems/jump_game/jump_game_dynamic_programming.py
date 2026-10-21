def canJump(nums: list[int]) -> bool:
    n = len(nums)
    if n == 0:
        return True

    dp = [False] * n
    dp[-1] = True

    for i in range(n - 2, -1, -1):
        max_jump = min(i + nums[i], n - 1)
        for j in range(i + 1, max_jump + 1):
            if dp[j]:
                dp[i] = True
                break

    return dp[0]
