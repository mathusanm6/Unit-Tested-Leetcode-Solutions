#include "find_the_index_of_the_first_occurrence_in_a_string.h"

#include <cstddef>
#include <string>
#include <string_view>

int strStr(const std::string& haystack, const std::string& needle) {
    const std::size_t n = haystack.size();
    const std::size_t m = needle.size();

    if (m == 0) {
        return 0;
    }
    if (n < m) {
        return -1;
    }

    const std::string_view h(haystack);
    const std::string_view nd(needle);

    for (std::size_t i = 0; i <= n - m; ++i) {
        // substr on string_view is O(1) - no copying/allocation
        if (h.substr(i, m) == nd) {
            return static_cast<int>(i);
        }
    }

    return -1;
}
