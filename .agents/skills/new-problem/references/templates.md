# Templates and code adaptation

File templates for Step 4 of `SKILL.md`, plus the mechanical adaptation rules.

## `BUILD.bazel`

Single solution:
```python
load("//problems:defs.bzl", "leetcode_problem")

leetcode_problem()
```

Multiple solutions:
```python
load("//problems:defs.bzl", "leetcode_problem")

leetcode_problem(
    variants = [
        "hash_map",
        "brute_force",
    ],
)
```
*(For tree problems using `TreeNode`, pass `extra_cc_deps = ["//common/trees"]` and `extra_py_deps = ["//common"]`).*

## `config.yml`

Single solution:
```yaml
problem:
  number: 88
  title: "Merge Sorted Array"
  leetcode_url: "https://leetcode.com/problems/merge-sorted-array/"
  difficulty: "easy"
  tags: ["Two Pointers"]

solutions:
  python: "problems/merge_sorted_array/merge_sorted_array.py"
  cpp: "problems/merge_sorted_array/merge_sorted_array.cc"

complexity:
  time: "O(m + n)"
  space: "O(1)"

notes: ""
readme_link: ""
```

Multiple solutions:
```yaml
problem:
  number: 1
  title: "Two Sum"
  leetcode_url: "https://leetcode.com/problems/two-sum/"
  difficulty: "easy"
  tags: ["Arrays & Hashing"]

solutions:
  - name: "Hash Map"
    python: "problems/two_sum/two_sum_hash_map.py"
    cpp: "problems/two_sum/two_sum_hash_map.cc"
    time: "O(n)"
    space: "O(n)"
  - name: "Brute Force"
    python: "problems/two_sum/two_sum_brute_force.py"
    cpp: "problems/two_sum/two_sum_brute_force.cc"
    time: "O(n^2)"
    space: "O(1)"

notes: ""
readme_link: ""
```

## `<snake>.py`

The project targets Python 3.14.8 (`.python-version`, `pyproject.toml`, CI); don't downgrade syntax.
A **free function** (never `class Solution`, no `self`), modern type hints (`list[int]`, `X | None`),
no `from typing import ...` for builtins.

```python
def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    ...
```

## `<snake>_test.py`

Single solution:
```python
"""Test cases for the merge function."""

import pytest
from merge_sorted_array import merge
```

Multiple solutions:
```python
"""Test cases for the two_sum function."""

import importlib
import os

import pytest

_module_name = os.environ.get("LEETCODE_SOLUTION_MODULE", "two_sum_hash_map")
_solution_mod = importlib.import_module(_module_name)
twoSum = _solution_mod.twoSum
```


@pytest.mark.parametrize(
    "nums1, m, nums2, n, expected",
    [
        ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),  # Basic case
        ([], 0, [], 0, []),  # Empty arrays
    ],
    ids=[
        "basic_case",
        "both_empty",
    ],
)
def test_merge(nums1, m, nums2, n, expected):
    merge(nums1, m, nums2, n)
    assert nums1 == expected
```

## `<snake>.h`

```cpp
#pragma once

#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
```

## `<snake>.cc`

```cpp
#include "merge_sorted_array.h"
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    ...
}
```

## `<snake>_test.cc`

GoogleTest value-parameterised tests with C++20 designated initialisers:

```cpp
#include "merge_sorted_array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

struct MergeSortedArrayCase {
    std::string test_name;
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
};

using MergeSortedArrayTest = ::testing::TestWithParam<MergeSortedArrayCase>;

TEST_P(MergeSortedArrayTest, TestCases) {
    MergeSortedArrayCase testCase = GetParam();
    merge(testCase.nums1, testCase.m, testCase.nums2, testCase.n);
    EXPECT_EQ(testCase.nums1, testCase.expected);
}

INSTANTIATE_TEST_SUITE_P(
    MergeSortedArrayTestCases, MergeSortedArrayTest,
    ::testing::Values(
        MergeSortedArrayCase{.test_name = "BasicExample",
                             .nums1 = {1, 2, 3, 0, 0, 0},
                             .m = 3,
                             .nums2 = {2, 5, 6},
                             .n = 3,
                             .expected = {1, 2, 2, 3, 5, 6}}),
    [](const ::testing::TestParamInfo<MergeSortedArrayCase> &info) { return info.param.test_name; });
```

## Tree problems (`TreeNode`)

- Python solution: `from common import TreeNode`.
- Python test: add repo root to `sys.path`:
  ```python
  import sys
  from pathlib import Path

  root_dir = Path(__file__).parent.parent.parent
  sys.path.insert(0, str(root_dir))

  from <snake> import <fn>
  from common import TreeNode
  ```
- C++: `#include "../../common/trees/treenode.h"`.

## Adapting the code (mechanical changes only)

- **Always** remove `class Solution:` / `class Solution { public: ... };` and `self`, de-indent, and
  make it a free function. Helper methods become free functions (Python: nested or module-level; C++:
  anonymous namespace in `.cc`).
- Add missing `#include`s, move the signature to `.h`.
- Python: replace `typing.List[int]` by `list[int]`, `Optional[X]` by `X | None`.
- C++: use `std::size_t` for indexing where appropriate to avoid signed/unsigned comparison warnings under `-Wall -Wextra -Wpedantic`.
- Keep the LeetCode function name unchanged.
