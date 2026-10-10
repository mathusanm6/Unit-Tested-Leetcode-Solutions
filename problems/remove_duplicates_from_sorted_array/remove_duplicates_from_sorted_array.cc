#include "remove_duplicates_from_sorted_array.h"

#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int write_index = 0;
    for (int num : nums) {
        if (write_index < 1 || num != nums[write_index - 1]) {
            nums[write_index] = num;
            write_index += 1;
        }
    }
    return write_index;
}
