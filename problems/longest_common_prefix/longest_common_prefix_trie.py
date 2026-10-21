from common import PrefixTree


def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ""
    prefix_tree = PrefixTree()
    for s in strs:
        if not s:
            return ""
        prefix_tree.insert(s)
    return prefix_tree.longest_common_prefix()
