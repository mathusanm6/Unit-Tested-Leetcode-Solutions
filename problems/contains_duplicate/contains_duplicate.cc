#include "contains_duplicate.h"

#include <unordered_set>
#include <vector>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    seen.reserve(nums.size());
    for (const int& num : nums) {
        if (const auto iter = seen.find(num); iter != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}
