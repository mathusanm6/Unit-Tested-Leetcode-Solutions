def rotate(nums: list[int], k: int) -> None:
    """Rotate nums one position at a time, using constant extra space."""
    n = len(nums)
    if n == 0:
        return

    for _ in range(k % n):
        last = nums[-1]
        nums[1:] = nums[:-1]
        nums[0] = last
