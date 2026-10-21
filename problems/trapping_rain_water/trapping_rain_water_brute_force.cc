#include "trapping_rain_water.h"

#include <algorithm>
#include <vector>

int trap(std::vector<int>& height) {
    const int n = static_cast<int>(height.size());
    if (n == 0) {
        return 0;
    }

    int water = 0;
    for (int i = 0; i < n; ++i) {
        int leftMax = 0;
        for (int j = 0; j <= i; ++j) {
            leftMax = std::max(leftMax, height[j]);
        }
        int rightMax = 0;
        for (int j = i; j < n; ++j) {
            rightMax = std::max(rightMax, height[j]);
        }
        water += std::min(leftMax, rightMax) - height[i];
    }

    return water;
}
