#include "rotate_array.h"

#include <vector>

namespace {

void reverse(std::vector<int>& nums, int left, int right) {
    while (left < right) {
        const int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

}  // namespace

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return;
    }

    k %= n;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}