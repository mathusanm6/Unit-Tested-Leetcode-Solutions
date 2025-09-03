from common import TreeNode
from math import inf
from typing import Optional, Tuple


def minimumFlips(root: Optional[TreeNode], result: bool) -> int:
    def dfs(node: Optional[TreeNode]) -> Tuple[int, int]:
        """Returns a tuple (min_flips_to_false, min_flips_to_true)"""
        if node is None:
            return inf, inf

        x = node.val
        if x in (0, 1):
            return (1, 0) if x == 1 else (0, 1)

        left_false, left_true = dfs(node.left)
        right_false, right_true = dfs(node.right)
        if x == 2:  # OR
            return (
                left_false + right_false,
                min(
                    left_true + right_false,
                    left_false + right_true,
                    left_true + right_true,
                ),
            )
        elif x == 3:  # AND
            return (
                min(
                    left_false + right_false,
                    left_false + right_true,
                    left_true + right_false,
                ),
                left_true + right_true,
            )
        elif x == 4:  # XOR
            return (
                min(left_false + right_false, left_true + right_true),
                min(left_false + right_true, left_true + right_false),
            )
        elif x == 5:  # NOT
            return (left_true, left_false)
        else:
            raise ValueError(f"Unknown operation: {x}")

    return dfs(root)[int(result)]
