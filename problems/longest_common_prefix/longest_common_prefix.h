#pragma once

#include <string>
#include <vector>

#include "../../common/tries/trie.h"

class ExtendedPrefixTree : public PrefixTree {
   public:
    std::string longest_common_prefix() const {
        std::string res = "";
        const TrieNode* curr = get_root();

        // Stop if there's branching OR if we reached the end of a word
        while (curr->children.size() == 1 && !curr->is_end) {
            auto it = curr->children.begin();
            res += it->first;
            curr = it->second;
        }
        return res;
    }
};

std::string longestCommonPrefix(const std::vector<std::string>& strs);
