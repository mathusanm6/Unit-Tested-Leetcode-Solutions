#include "trapping_rain_water.h"

#include <algorithm>
#include <vector>

int trap(std::vector<int>& height) {
    if (height.empty()) {
        return 0;
    }

    const int n = static_cast<int>(height.size());
    std::vector<int> leftMax(n);
    std::vector<int> rightMax(n);

    // Fill left prefix maximums
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    // Fill right suffix maximums
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    // Accumulate water column by column
    int water = 0;
    for (int i = 0; i < n; ++i) {
        water += std::min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
}
