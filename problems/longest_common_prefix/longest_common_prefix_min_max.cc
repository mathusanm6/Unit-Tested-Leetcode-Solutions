#include "longest_common_prefix.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    const auto [minIt, maxIt] = std::ranges::minmax_element(strs);
    const std::string& s1 = *minIt;
    const std::string& s2 = *maxIt;

    size_t i = 0;
    while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        ++i;
    }

    return s1.substr(0, i);
}
