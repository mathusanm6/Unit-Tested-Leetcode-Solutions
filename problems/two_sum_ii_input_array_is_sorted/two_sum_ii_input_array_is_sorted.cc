#include "two_sum_ii_input_array_is_sorted.h"

#include <cstddef>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    if (numbers.size() < 2) {
        return {};
    }

    std::size_t l = 0;
    std::size_t r = numbers.size() - 1;

    while (l < r) {
        const int curr = numbers[l] + numbers[r];
        if (curr == target) {
            return {static_cast<int>(l + 1), static_cast<int>(r + 1)};
        }
        if (curr < target) {
            ++l;
        } else {
            --r;
        }
    }

    return {};
}
