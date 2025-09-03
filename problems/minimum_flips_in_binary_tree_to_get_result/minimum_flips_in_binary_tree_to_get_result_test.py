"""Test cases for the minimumFlips function."""

import sys
from pathlib import Path

import pytest

# Add the root directory to Python path
root_dir = Path(__file__).parent.parent.parent
sys.path.insert(0, str(root_dir))

from common import TreeNode  # noqa: E402
from minimum_flips_in_binary_tree_to_get_result import minimumFlips  # noqa: E402


@pytest.mark.parametrize(
    "root, result, expected",
    [
        (TreeNode(0), True, 1),  # Flip leaf node from 0 to 1
        (TreeNode(1), True, 0),  # Leaf node already 1
        (TreeNode(2, TreeNode(0), TreeNode(0)), True, 1),  # OR gate, flip one child
        (
            TreeNode(2, TreeNode(1), TreeNode(1)),
            False,
            2,
        ),  # OR gate, flip both children
        (TreeNode(3, TreeNode(1), TreeNode(1)), True, 0),  # AND gate, already true
        (TreeNode(3, TreeNode(1), TreeNode(0)), True, 1),  # AND gate, flip one child
        (TreeNode(4, TreeNode(1), TreeNode(0)), True, 0),  # XOR gate, already true
        (TreeNode(4, TreeNode(1), TreeNode(1)), False, 0),  # XOR gate, already false
        (TreeNode(5, TreeNode(0)), True, 0),  # NOT gate, already true
        (TreeNode(5, TreeNode(1)), False, 0),  # NOT gate, already false
        (
            TreeNode(
                2, TreeNode(3, TreeNode(1), TreeNode(0)), TreeNode(5, TreeNode(0))
            ),
            True,
            0,
        ),  # Complex tree: OR(AND(1,0), NOT(0)) = 1, already true
        (
            TreeNode(
                3, TreeNode(2, TreeNode(0), TreeNode(0)), TreeNode(5, TreeNode(1))
            ),
            False,
            0,
        ),  # Complex tree: AND(OR(0,0), NOT(1)) = 0, already false
        (
            TreeNode(
                4,
                TreeNode(2, TreeNode(1), TreeNode(0)),
                TreeNode(3, TreeNode(1), TreeNode(1)),
            ),
            True,
            1,
        ),  # Complex tree: XOR(OR(1,0), AND(1,1)) = 1, need 1 flip to make false
        (
            TreeNode(
                4,
                TreeNode(2, TreeNode(1), TreeNode(1)),
                TreeNode(3, TreeNode(1), TreeNode(0)),
            ),
            False,
            1,
        ),  # Complex tree: XOR(OR(1,1), AND(1,0)) = 1, flip one child to make it 0
        (
            TreeNode(
                4,
                TreeNode(0),
                TreeNode(
                    2, TreeNode(0), TreeNode(5, None, TreeNode(5, None, TreeNode(1)))
                ),
            ),
            True,
            0,
        ),  # Complex tree: XOR(0, OR(0, NOT(NOT(1)))) = 1, already true
    ],
    ids=[
        "leaf_0_to_true",
        "leaf_1_already_true",
        "or_gate_flip_child",
        "or_gate_to_false",
        "and_gate_already_true",
        "and_gate_flip_child",
        "xor_gate_already_true",
        "xor_gate_already_false",
        "not_gate_already_true",
        "not_gate_already_false",
        "complex_tree_or_already_true",
        "complex_tree_and_already_false",
        "complex_tree_xor_need_flip",
        "complex_tree_xor_to_false",
        "complex_xor_tree_with_not_right_child",
    ],
)
def test_minimum_flips(root, result, expected):
    assert minimumFlips(root, result) == expected
