def twoSum(nums: list[int], target: int) -> list[int]:
    index_of = {}
    for idx, num in enumerate(nums):
        need = target - num
        if need in index_of:
            return [index_of[need], idx]
        index_of[num] = idx
    return [-1, -1]  # If no solution is found
