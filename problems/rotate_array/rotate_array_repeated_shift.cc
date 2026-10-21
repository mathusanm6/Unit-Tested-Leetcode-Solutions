#include "rotate_array.h"

#include <vector>

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return;
    }

    for (int step = 0; step < k % n; step++) {
        const int last = nums.back();
        for (int index = n - 1; index > 0; index--) {
            nums[index] = nums[index - 1];
        }
        nums[0] = last;
    }
}