#include "longest_common_prefix.h"

#include <cstddef>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    std::string prefix = strs[0];
    for (size_t i = 1; i < strs.size(); ++i) {
        while (!strs[i].starts_with(prefix)) {
            prefix.pop_back();
            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}
