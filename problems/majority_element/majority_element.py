def majorityElement(nums: list[int]) -> int:
    res = 0
    count = 0
    for num in nums:
        if count == 0:
            res = num
        if num == res:
            count += 1
        else:
            count -= 1
    return res
