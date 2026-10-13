#include "product_of_array_except_self.h"

#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> res(n, 1);

    int prefixProduct = 1;
    for (int i = 0; i < n; i++) {
        res[i] *= prefixProduct;
        prefixProduct *= nums[i];
    }

    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }

    return res;
}
