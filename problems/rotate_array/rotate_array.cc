#include "rotate_array.h"

#include <vector>

namespace {

void swap(std::vector<int>& _nums, int l, int r) {
    while (l < r) {
        const int tmp = _nums[l];
        _nums[l] = _nums[r];
        _nums[r] = tmp;
        l++;
        r--;
    }
}

}  // namespace

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    k = k % n;
    swap(nums, 0, n - k - 1);
    swap(nums, n - k, n - 1);
    swap(nums, 0, n - 1);
}
