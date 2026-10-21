def rotate(nums: list[int], k: int) -> None:
    """Rotate nums to the right by k positions using a copy of the result."""
    n = len(nums)
    if n == 0:
        return

    k %= n
    nums[:] = nums[-k:] + nums[:-k]
