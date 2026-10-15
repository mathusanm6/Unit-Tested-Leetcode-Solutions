# Unit-Tested LeetCode Solutions

<div align="center">

### 🔬 Code Health & Testing

[![C++ Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/cpp-test.yml?branch=main&label=C%2B%2B%20Tests&logo=cplusplus&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/cpp-test.yml)
[![Python Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/python-test.yml?branch=main&label=Python%20Tests&logo=python&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/python-test.yml)

### 🔍 Code Quality & Linting

[![C++ Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/cpp-lint.yml?branch=main&label=C%2B%2B%20Linter&logo=cplusplus&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/cpp-lint.yml)
[![Python Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/python-lint.yml?branch=main&label=Python%20Linter&logo=python&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/python-lint.yml)

### 📊 Repository Stats

[![Last Commit](https://img.shields.io/github/last-commit/mathusanm6/LeetCode?style=for-the-badge&logo=git&logoColor=white&color=blue)](https://github.com/mathusanm6/LeetCode/commits/main)
[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-27-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)
[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-27-blue?style=for-the-badge&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)

</div>

## Description

This repository contains comprehensive, unit-tested solutions to LeetCode problems implemented in both **C++20** and **Python 3**. Each solution includes:

- 🧪 **Comprehensive test suites** with multiple test cases
- 📝 **Detailed documentation** with complexity analysis
- 🔧 **Automated code quality** checks and formatting
- 🚀 **CI/CD pipeline** with automated testing and linting

## 📁 Project Structure

```
├── problems/                    # Problem solutions organized by name
│   ├── defs.bzl                 # Starlark macro for defining problem targets
│   ├── two_sum/                 # Individual problem directories
│   │   ├── BUILD.bazel          # Problem target definitions
│   │   ├── config.yml           # Problem metadata and configuration
│   │   ├── two_sum.py           # Python solution
│   │   ├── two_sum.cc           # C++ solution
│   │   ├── two_sum.h            # C++ header
│   │   ├── two_sum_test.py      # Python unit tests
│   │   └── two_sum_test.cc      # C++ unit tests
│   └── ...
├── common/                      # Shared data structures (e.g. TreeNode)
├── config/                      # Global configuration files
│   ├── difficulties.yml         # Difficulty level definitions
│   └── tags.yml                 # Problem tag categories
├── scripts/                     # Automation and utility scripts
│   ├── format.sh                # Code formatting (C++ & Python)
│   ├── lint.sh                  # Code linting (C++ & Python)
│   ├── install_hooks.sh         # Git hooks installer
│   ├── uninstall_hooks.sh       # Git hooks uninstaller
│   ├── generate_readme.py       # Auto-generate README content
│   ├── update_badges.py         # Update repository badges
│   └── update_badges.sh         # Badge update automation
├── tools/                       # Build tools & test runners
├── .github/workflows/           # CI/CD automation
│   ├── cpp-test.yml             # C++ Bazel testing
│   ├── python-test.yml          # Python Bazel testing
│   ├── cpp-lint.yml             # C++ clang-tidy and clang-format
│   ├── python-lint.yml          # Python ruff lint and format
│   └── pr-size-labeler.yml      # PR size labeling
├── MODULE.bazel                 # External dependency management (Bzlmod)
├── BUILD.bazel                  # Root package definition
├── .bazelrc                     # Bazel compiler flags & options
├── requirements.txt             # Python dependencies
├── requirements_lock.txt        # Pinned dependencies for rules_python
├── .clang-format                # C++ code formatting rules
└── .clang-tidy                  # C++ linting configuration
```

## 🛠️ Technologies & Tools

### Languages & Standards

- **C++**: C++20 with modern features and strict compiler warnings (`-std=c++20 -Wall -Wextra -Wpedantic`)
- **Python**: Python 3.14 with type hints and modern syntax

### Testing Frameworks

- **C++**: Google Test (`googletest@1.18.0.bcr.1`) hermetically managed via Bazel Bzlmod
- **Python**: pytest hermetically managed via `rules_python`

### Code Quality Tools

- **C++ Formatting**: `clang-format` for consistent code style
- **C++ Linting**: `clang-tidy` for static analysis and best practices
- **Python Formatting & Linting**: `ruff` for fast formatting and linting

### Build & Automation

- **Bazel**: Multi-language, hermetic build and test system with sandboxed execution and transitive caching
- **GitHub Actions**: Automated CI/CD running native Bazel test targets

## 🧪 Running Tests with Bazel

All test targets run sandboxed and in parallel with action caching. No system installation of Google Test or CMake is required.

```bash
# Run all tests (both C++ and Python) across the entire repo
bazel test //problems/...

# Run all tests for a specific problem (both languages)
bazel test //problems/two_sum:test

# Run only C++ tests
bazel test //problems/two_sum:cc_test          # for a specific problem
bazel test --test_tag_filters=cc //problems/... # for all problems

# Run only Python tests
bazel test //problems/two_sum:py_test          # for a specific problem
bazel test --test_tag_filters=py //problems/... # for all problems
```

## 🎨 Code Quality

This project maintains high code quality standards through automated tooling:

### Formatting & Linting

```bash
# Format code (C++ with clang-format, Python with ruff)
./scripts/format.sh          # format both
./scripts/format.sh cpp      # format C++ only
./scripts/format.sh py       # format Python only

# Lint code (C++ with clang-tidy, Python with ruff)
./scripts/lint.sh            # lint both
./scripts/lint.sh cpp        # lint C++ only
./scripts/lint.sh py         # lint Python only
```

### Git Pre-Commit Hooks

Install the pre-commit hook to automatically format, lint, update badges, and run tests before committing:

```bash
./scripts/install_hooks.sh
```

### Automation & Documentation

```bash
# Regenerate README from problem configurations
bazel run //scripts:generate_readme

# Update README badges with current solution counts
bazel run //scripts:update_badges
# or: ./scripts/update_badges.sh

# Clean build artifacts
bazel clean
```

### 🔄 Continuous Integration

The GitHub Actions CI pipeline runs 4 focused workflows on both pull requests and pushes to `main`:

- **⚡ C++ / Test** (`cpp-test.yml`): Parallel sandboxed GoogleTest execution via Bazel
- **🐍 Python / Test** (`python-test.yml`): Parallel sandboxed pytest execution via Bazel
- **🔍 C++ / Lint** (`cpp-lint.yml`): Static analysis (`clang-tidy`) and format enforcement (`clang-format`)
- **🔍 Python / Lint** (`python-lint.yml`): Ruff linting and format enforcement


## 🧮 Algorithms & Data Structures

This repository covers a comprehensive range of algorithmic patterns and data structures commonly found in technical interviews:

- [Arrays & Hashing](#arrays--hashing)
- [Two Pointers](#two-pointers)
- [Sliding Window](#sliding-window)
- [Stack](#stack)
- [Binary Search](#binary-search)
- [Linked List](#linked-list)
- [Trees](#trees)
- [Heap / Priority Queue](#heap-/-priority-queue)
- [Backtracking](#backtracking)
- [Tries](#tries)
- [Graphs](#graphs)
- [Advanced Graphs](#advanced-graphs)
- [1-D Dynamic Programming](#1-d-dynamic-programming)
- [2-D Dynamic Programming](#2-d-dynamic-programming)
- [Greedy](#greedy)
- [Intervals](#intervals)
- [Math & Geometry](#math--geometry)
- [Bit Manipulation](#bit-manipulation)

## Arrays & Hashing

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [Python](./problems/two_sum/two_sum.py), [C++](./problems/two_sum/two_sum.cc) | _O(n)_ | _O(n)_ | Easy |  |  |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [Python](./problems/roman_to_integer/roman_to_integer.py), [C++](./problems/roman_to_integer/roman_to_integer.cc) | _O(n)_ | _O(1)_ | Easy |  |  |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | [Python](./problems/group_anagrams/group_anagrams.py), [C++](./problems/group_anagrams/group_anagrams.cc) | _O(n * k log k)_ | _O(n)_ | Medium |  | For C++, the complexity is _O(n * k log k)_, where n is the number of strings and k is the maximum length of a string. But for Python, the complexity is _O(n * k)_ as there is no sorting involved. |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/) | [Python](./problems/majority_element/majority_element.py), [C++](./problems/majority_element/majority_element.cc) | _O(n)_ | _O(1)_ | Easy |  | Using Boyer-Moore Majority Vote Algorithm. |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [Python](./problems/contains_duplicate/contains_duplicate.py), [C++](./problems/contains_duplicate/contains_duplicate.cc) | _O(n)_ | _O(n)_ | Easy |  |  |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | [Python](./problems/product_of_array_except_self/product_of_array_except_self.py), [C++](./problems/product_of_array_except_self/product_of_array_except_self.cc) | _O(n)_ | _O(1)_ | Medium |  | We are using prefix sum's logic. |
| 274 | [H-Index](https://leetcode.com/problems/h-index/) | [Python](./problems/h_index/h_index.py), [C++](./problems/h_index/h_index.cc) | _O(n log n)_ | _O(1)_ | Medium |  |  |
| 380 | [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) | [Python](./problems/insert_delete_getrandom_o1/insert_delete_getrandom_o1.py), [C++](./problems/insert_delete_getrandom_o1/insert_delete_getrandom_o1.cc) | _O(1)_ | _O(n)_ | Medium |  |  |
| 2303 | [Calculate Amount Paid In Taxes](https://leetcode.com/problems/calculate-amount-paid-in-taxes/) | [Python](./problems/calculate_amount_paid_in_taxes/calculate_amount_paid_in_taxes.py), [C++](./problems/calculate_amount_paid_in_taxes/calculate_amount_paid_in_taxes.cc) | _O(n)_ | _O(1)_ | Easy |  |  |

## Two Pointers

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [Python](./problems/remove_duplicates_from_sorted_array/remove_duplicates_from_sorted_array.py), [C++](./problems/remove_duplicates_from_sorted_array/remove_duplicates_from_sorted_array.cc) | _O(n)_ | _O(1)_ | Easy |  |  |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [Python](./problems/remove_element/remove_element.py), [C++](./problems/remove_element/remove_element.cc) | _O(n)_ | _O(1)_ | Easy |  |  |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [Python](./problems/trapping_rain_water/trapping_rain_water.py), [C++](./problems/trapping_rain_water/trapping_rain_water.cc) | _O(n)_ | _O(1)_ | Hard |  |  |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [Python](./problems/remove_duplicates_from_sorted_array_ii/remove_duplicates_from_sorted_array_ii.py), [C++](./problems/remove_duplicates_from_sorted_array_ii/remove_duplicates_from_sorted_array_ii.cc) | _O(n)_ | _O(1)_ | Medium |  |  |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | [Python](./problems/merge_sorted_array/merge_sorted_array.py), [C++](./problems/merge_sorted_array/merge_sorted_array.cc) | _O(m + n)_ | _O(1)_ | Easy |  |  |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [Python](./problems/valid_palindrome/valid_palindrome.py), [C++](./problems/valid_palindrome/valid_palindrome.cc) | _O(n)_ | _O(1)_ | Easy |  |  |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [Python](./problems/rotate_array/rotate_array.py), [C++](./problems/rotate_array/rotate_array.cc) | _O(n)_ | _O(1)_ | Medium |  |  |

## Trees

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 2313 | [Minimum Flips in Binary Tree to Get Result](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result/) | [Python](./problems/minimum_flips_in_binary_tree_to_get_result/minimum_flips_in_binary_tree_to_get_result.py), [C++](./problems/minimum_flips_in_binary_tree_to_get_result/minimum_flips_in_binary_tree_to_get_result.cc) | _O(n)_ | _O(1)_ | Hard |  | _n_ is the number of nodes in the binary tree. |

## Backtracking

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 1087 | [Brace Expansion](https://leetcode.com/problems/brace-expansion/) | [Python](./problems/brace_expansion/brace_expansion.py), [C++](./problems/brace_expansion/brace_expansion.cc) | _O(M^K + M log M)_ | _O(M^K)_ | Medium |  | M = max choices per brace set, K = number of brace sets. M^K for generating combinations, M log M for sorting. |

## Tries

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [Python](./problems/longest_common_prefix/longest_common_prefix.py), [C++](./problems/longest_common_prefix/longest_common_prefix.cc) | _O(n * m)_ | _O(n * m)_ | Easy |  |  |

## Graphs

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/) | [Python](./problems/evaluate_division/evaluate_division.py), [C++](./problems/evaluate_division/evaluate_division.cc) | _O(N + M)_ | _O(N)_ | Medium |  | N = number of equations, M = number of queries. |

## 1-D Dynamic Programming

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [Python](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii.py), [C++](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii.cc) | _O(n)_ | _O(1)_ | Medium |  |  |

## Greedy

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [Python](./problems/integer_to_roman/integer_to_roman.py), [C++](./problems/integer_to_roman/integer_to_roman.cc) | _O(1)_ | _O(1)_ | Medium |  |  |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | [Python](./problems/jump_game_ii/jump_game_ii.py), [C++](./problems/jump_game_ii/jump_game_ii.cc) | _O(n)_ | _O(1)_ | Medium |  |  |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | [Python](./problems/jump_game/jump_game.py), [C++](./problems/jump_game/jump_game.cc) | _O(n)_ | _O(1)_ | Medium |  |  |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [Python](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock.py), [C++](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock.cc) | _O(n)_ | _O(1)_ | Easy |  |  |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | [Python](./problems/gas_station/gas_station.py), [C++](./problems/gas_station/gas_station.cc) | _O(n)_ | _O(1)_ | Medium |  |  |
| 135 | [Candy](https://leetcode.com/problems/candy/) | [Python](./problems/candy/candy.py), [C++](./problems/candy/candy.cc) | _O(n)_ | _O(n)_ | Hard |  | We do it in two passes: one left to right and other right to left. |
