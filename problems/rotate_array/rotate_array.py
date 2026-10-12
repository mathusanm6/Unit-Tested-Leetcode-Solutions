def rotate(nums: list[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    n = len(nums)
    k = k % n

    def swap(_nums: list[int], l: int, r: int) -> None:
        while l < r:
            _nums[l], _nums[r] = _nums[r], _nums[l]
            l += 1
            r -= 1

    swap(nums, 0, n - k - 1)
    swap(nums, n - k, n - 1)
    swap(nums, 0, n - 1)
