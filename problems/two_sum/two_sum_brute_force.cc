#include "two_sum.h"

#include <vector>

std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    const int numCount = static_cast<int>(nums.size());
    for (int i = 0; i < numCount; ++i) {
        for (int j = i + 1; j < numCount; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
