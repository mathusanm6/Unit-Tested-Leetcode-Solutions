#include "remove_duplicates_from_sorted_array_ii.h"

#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int write_index = 0;
    for (int num : nums) {
        if (write_index < 2 || num != nums[write_index - 2]) {
            nums[write_index] = num;
            write_index += 1;
        }
    }
    return write_index;
}
