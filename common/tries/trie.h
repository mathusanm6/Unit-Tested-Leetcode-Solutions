#pragma once

#include <string>
#include <unordered_map>

class TrieNode {
   public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end = false;

    TrieNode() = default;

    ~TrieNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }

    TrieNode(const TrieNode&) = delete;
    TrieNode& operator=(const TrieNode&) = delete;
    TrieNode(TrieNode&&) = delete;
    TrieNode& operator=(TrieNode&&) = delete;
};

class PrefixTree {
   public:
    PrefixTree() { root_ = new TrieNode(); }

    ~PrefixTree() { delete root_; }

    PrefixTree(const PrefixTree&) = delete;
    PrefixTree& operator=(const PrefixTree&) = delete;
    PrefixTree(PrefixTree&&) = delete;
    PrefixTree& operator=(PrefixTree&&) = delete;

    void insert(const std::string& word) {
        TrieNode* curr = root_;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->is_end = true;
    }

    std::string longest_common_prefix() {
        std::string res = "";
        TrieNode* curr = root_;

        // Stop if there's branching OR if we reached the end of a word
        while (curr->children.size() == 1 && !curr->is_end) {
            auto it = curr->children.begin();
            res += it->first;
            curr = it->second;
        }
        return res;
    }

   private:
    TrieNode* root_;
};
