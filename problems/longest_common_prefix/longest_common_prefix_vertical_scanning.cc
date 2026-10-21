#include "longest_common_prefix.h"

#include <cstddef>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    const std::string& first = strs[0];
    for (size_t i = 0; i < first.size(); ++i) {
        const char ch = first[i];
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i == strs[j].size() || strs[j][i] != ch) {
                return first.substr(0, i);
            }
        }
    }

    return first;
}
