"""Common Trie data structures."""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class PrefixTree:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.is_end = True

    def longest_common_prefix(self) -> str:
        res = []
        curr = self.root
        # Stop if there's branching OR if we reached the end of a word
        while len(curr.children) == 1 and not curr.is_end:
            c = next(iter(curr.children))
            res.append(c)
            curr = curr.children[c]
        return "".join(res)
