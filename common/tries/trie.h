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

    TrieNode* get_root() { return root_; }
    const TrieNode* get_root() const { return root_; }

   private:
    TrieNode* root_;
};
