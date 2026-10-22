#include "3sum.h"

#include <algorithm>
#include <ranges>  // NOLINT(misc-include-cleaner) needed for std::ranges::sort
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::ranges::sort(nums);

    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> res;

    for (int i = 0; i < n - 2; ++i) {
        // Since the array is sorted, no 3 positive numbers can sum to 0
        if (nums[i] > 0) {
            break;
        }

        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            const int curr = nums[i] + nums[l] + nums[r];
            if (curr == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                ++l;
                --r;
                // Skip duplicate values for the two-pointer window
                while (l < r && nums[l] == nums[l - 1]) {
                    ++l;
                }
                while (l < r && nums[r] == nums[r + 1]) {
                    --r;
                }
            } else if (curr < 0) {
                ++l;
            } else {
                --r;
            }
        }
    }

    return res;
}
