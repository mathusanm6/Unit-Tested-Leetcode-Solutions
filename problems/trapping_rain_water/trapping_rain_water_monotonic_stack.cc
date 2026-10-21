#include "trapping_rain_water.h"

#include <algorithm>
#include <stack>
#include <vector>

int trap(std::vector<int>& height) {
    std::stack<int> stack;  // Stores indices in decreasing height order
    int water = 0;
    const int n = static_cast<int>(height.size());

    for (int current = 0; current < n; ++current) {
        // While the current bar is taller than the stack top, a basin is closed
        while (!stack.empty() && height[current] > height[stack.top()]) {
            const int top = stack.top();
            stack.pop();

            if (stack.empty()) {
                break;
            }

            const int left = stack.top();
            const int distance = current - left - 1;
            const int boundedHeight = std::min(height[left], height[current]) - height[top];
            water += distance * boundedHeight;
        }

        stack.push(current);
    }

    return water;
}
