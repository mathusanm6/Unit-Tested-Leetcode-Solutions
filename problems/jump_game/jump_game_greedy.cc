#include <vector>
#include "jump_game.h"

bool canJump(std::vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    int goalPost = n - 1;
    for (int rI = n - 2; rI >= 0; rI--) {
        const int maxJump = nums[rI];
        if (goalPost - rI <= maxJump) {
            goalPost = rI;
        }
    }

    return goalPost == 0;
}
