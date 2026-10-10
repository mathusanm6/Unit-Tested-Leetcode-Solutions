#include "majority_element.h"

#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int res = 0;
    int count = 0;
    for (const int num : nums) {
        if (count == 0) {
            res = num;
        }

        if (res == num) {
            count++;
        } else {
            count--;
        }
    }
    return res;
}
