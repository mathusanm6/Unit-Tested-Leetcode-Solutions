#include "trapping_rain_water.h"

#include <algorithm>
#include <vector>

int trap(std::vector<int>& height) {
    const int n = static_cast<int>(height.size());

    if (n == 0) {
        return 0;
    }

    int l = 0;
    int r = n - 1;
    int leftMax = height[0];
    int rightMax = height[r];
    int res = 0;

    while (l < r) {
        if (leftMax < rightMax) {
            l++;
            leftMax = std::max(leftMax, height[l]);
            res += leftMax - height[l];
        } else {
            r--;
            rightMax = std::max(rightMax, height[r]);
            res += rightMax - height[r];
        }
    }
    return res;
}
