#include "rotate_array.h"

#include <utility>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return;
    }

    k %= n;
    std::vector<int> rotated(nums);
    for (int index = 0; index < n; index++) {
        rotated[(index + k) % n] = nums[index];
    }
    nums = std::move(rotated);
}