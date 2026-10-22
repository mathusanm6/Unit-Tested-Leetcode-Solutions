#include "container_with_most_water.h"

#include <algorithm>
#include <cstddef>
#include <vector>

int maxArea(const std::vector<int>& height) {
    if (height.size() < 2) {
        return 0;
    }

    std::size_t l = 0;
    std::size_t r = height.size() - 1;
    int res = 0;

    while (l < r) {
        const int hl = height[l];
        const int hr = height[r];
        res = std::max(res, std::min(hl, hr) * static_cast<int>(r - l));

        if (hl <= hr) {
            ++l;
        } else {
            --r;
        }
    }

    return res;
}
