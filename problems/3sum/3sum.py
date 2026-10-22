def threeSum(nums: list[int]) -> list[list[int]]:
    nums.sort()

    n = len(nums)
    res = []

    for i in range(n - 2):
        # Since the array is sorted, no 3 positive numbers can sum to 0
        if nums[i] > 0:
            break

        # Skip duplicate values for the first element
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        l, r = i + 1, n - 1
        while l < r:
            curr = nums[i] + nums[l] + nums[r]
            if curr == 0:
                res.append([nums[i], nums[l], nums[r]])
                l += 1
                r -= 1
                # Skip duplicate values for the two-pointer window
                while l < r and nums[l] == nums[l - 1]:
                    l += 1
                while l < r and nums[r] == nums[r + 1]:
                    r -= 1
            elif curr < 0:
                l += 1
            else:
                r -= 1

    return res
