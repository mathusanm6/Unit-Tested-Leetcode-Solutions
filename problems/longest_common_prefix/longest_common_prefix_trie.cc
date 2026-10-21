#include "longest_common_prefix.h"

#include <string>
#include <vector>

#include "../../common/tries/trie.h"

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    PrefixTree prefixTree;
    for (const std::string& s : strs) {
        if (s.empty()) {
            return "";
        }
        prefixTree.insert(s);
    }

    return prefixTree.longest_common_prefix();
}
