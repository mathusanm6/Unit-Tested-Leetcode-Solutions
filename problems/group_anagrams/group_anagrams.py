import collections

from typing import List


def groupAnagrams(strs: List[str]) -> List[List[str]]:
    groups = collections.defaultdict(list)
    for s in strs:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord("a")] += 1
        groups[tuple(count)].append(s)
    return list(groups.values())
