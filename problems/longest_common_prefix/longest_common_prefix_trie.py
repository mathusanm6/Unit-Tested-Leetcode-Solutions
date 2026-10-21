from common import PrefixTree


class ExtendedPrefixTree(PrefixTree):
    def longest_common_prefix(self) -> str:
        res = []
        curr = self.root
        # Stop if there's branching OR if we reached the end of a word
        while len(curr.children) == 1 and not curr.is_end:
            c = next(iter(curr.children))
            res.append(c)
            curr = curr.children[c]
        return "".join(res)


def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ""
    prefix_tree = ExtendedPrefixTree()
    for s in strs:
        if not s:
            return ""
        prefix_tree.insert(s)
    return prefix_tree.longest_common_prefix()
