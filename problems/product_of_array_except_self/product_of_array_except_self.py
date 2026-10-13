def productExceptSelf(nums: list[int]) -> list[int]:
    n = len(nums)
    res = [1] * n

    prefix_product = 1
    for i in range(n):
        res[i] *= prefix_product
        prefix_product *= nums[i]

    suffix_product = 1
    for i in range(n - 1, -1, -1):
        res[i] *= suffix_product
        suffix_product *= nums[i]

    return res
