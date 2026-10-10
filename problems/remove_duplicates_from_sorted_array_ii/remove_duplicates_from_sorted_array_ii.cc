#include "remove_duplicates_from_sorted_array_ii.h"

#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int writeIndex = 0;
    for (const int num : nums) {
        if (writeIndex < 2 || num != nums[writeIndex - 2]) {
            nums[writeIndex] = num;
            writeIndex += 1;
        }
    }
    return writeIndex;
}
