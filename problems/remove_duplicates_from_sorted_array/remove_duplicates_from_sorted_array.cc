#include "remove_duplicates_from_sorted_array.h"

#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int writeIndex = 0;
    for (const int num : nums) {
        if (writeIndex < 1 || num != nums[writeIndex - 1]) {
            nums[writeIndex] = num;
            writeIndex += 1;
        }
    }
    return writeIndex;
}
