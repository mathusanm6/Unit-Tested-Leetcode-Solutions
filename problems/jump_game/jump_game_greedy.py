def canJump(nums: list[int]) -> bool:
    n = len(nums)
    goal_post = n - 1
    for r_i in range(n - 2, -1, -1):
        max_jump = nums[r_i]
        if goal_post - r_i <= max_jump:
            goal_post = r_i

    return goal_post == 0
