#include "two_sum.h"

#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    const int numCount = static_cast<int>(nums.size());
    std::unordered_map<int, int> indexOf;
    indexOf.reserve(nums.size());  // Reserve space to avoid rehashing
    for (int idx = 0; idx < numCount; ++idx) {
        const int num = nums[idx];
        const int need = target - num;
        if (const auto iterator = indexOf.find(need); iterator != indexOf.end()) {
            return {iterator->second, idx};
        }
        indexOf.emplace(num, idx);  // Note: no overwrite if x already exists
    }
    return {-1, -1};  // If no solution is found
}
