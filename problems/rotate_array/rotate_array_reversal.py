def rotate(nums: list[int], k: int) -> None:
    """Rotate nums to the right by k positions using three reversals."""
    n = len(nums)
    if n == 0:
        return

    k %= n

    def reverse(left: int, right: int) -> None:
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

    reverse(0, n - k - 1)
    reverse(n - k, n - 1)
    reverse(0, n - 1)
