#include "longest_common_prefix.h"

#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    ExtendedPrefixTree prefixTree;
    for (const std::string& s : strs) {
        if (s.empty()) {
            return "";
        }
        prefixTree.insert(s);
    }

    return prefixTree.longest_common_prefix();
}
