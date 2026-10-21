#include <algorithm>
#include <vector>
#include "jump_game_ii.h"

int jump(std::vector<int> &nums) {
    int res = 0;
    int l = 0;
    int r = 0;

    while (r < static_cast<int>(nums.size()) - 1) {
        int farthest = 0;
        for (int i = l; i < r + 1; i++) {
            farthest = std::max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        res++;
    }
    return res;
}
