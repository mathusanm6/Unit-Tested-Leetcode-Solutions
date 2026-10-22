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
[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-28-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)
[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-28-blue?style=for-the-badge&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)

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

- [Array / String](#array-/-string)
- [Two Pointers](#two-pointers)
- [Sliding Window](#sliding-window)
- [Matrix](#matrix)
- [Hashmap](#hashmap)
- [Intervals](#intervals)
- [Stack](#stack)
- [Linked List](#linked-list)
- [Binary Tree General](#binary-tree-general)
- [Binary Tree BFS](#binary-tree-bfs)
- [Binary Search Tree](#binary-search-tree)
- [Graph General](#graph-general)
- [Graph BFS](#graph-bfs)
- [Trie](#trie)
- [Backtracking](#backtracking)
- [Divide & Conquer](#divide--conquer)
- [Kadane's Algorithm](#kadane's-algorithm)
- [Binary Search](#binary-search)
- [Heap](#heap)
- [Bit Manipulation](#bit-manipulation)
- [Math](#math)
- [1D DP](#1d-dp)
- [Multidimensional DP](#multidimensional-dp)

## Array / String

| # | Title | Difficulty | Approach | Solution | Time | Space | Note |
|---|-------|------------|----------|----------|------|-------|------|
| 6 | [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/) | Medium | Row Buckets | [Python](./problems/zigzag_conversion/zigzag_conversion_row_buckets.py), [C++](./problems/zigzag_conversion/zigzag_conversion_row_buckets.cc) | _O(n)_ | _O(n)_ |  |
|  |  |  | Math | [Python](./problems/zigzag_conversion/zigzag_conversion_math.py), [C++](./problems/zigzag_conversion/zigzag_conversion_math.cc) | _O(n)_ | _O(1)_ |  |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | Medium | Math | [Python](./problems/integer_to_roman/integer_to_roman.py), [C++](./problems/integer_to_roman/integer_to_roman.cc) | _O(1)_ | _O(1)_ |  |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | Easy | Math | [Python](./problems/roman_to_integer/roman_to_integer.py), [C++](./problems/roman_to_integer/roman_to_integer.cc) | _O(n)_ | _O(1)_ |  |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | Easy | Vertical Scanning | [Python](./problems/longest_common_prefix/longest_common_prefix_vertical_scanning.py), [C++](./problems/longest_common_prefix/longest_common_prefix_vertical_scanning.cc) | _O(n * m)_ | _O(1)_ |  |
|  |  |  | Horizontal Scanning | [Python](./problems/longest_common_prefix/longest_common_prefix_horizontal_scanning.py), [C++](./problems/longest_common_prefix/longest_common_prefix_horizontal_scanning.cc) | _O(n * m)_ | _O(1)_ |  |
|  |  |  | Min / Max Lexicographical | [Python](./problems/longest_common_prefix/longest_common_prefix_min_max.py), [C++](./problems/longest_common_prefix/longest_common_prefix_min_max.cc) | _O(n * m)_ | _O(1)_ |  |
|  |  |  | Trie | [Python](./problems/longest_common_prefix/longest_common_prefix_trie.py), [C++](./problems/longest_common_prefix/longest_common_prefix_trie.cc) | _O(n * m)_ | _O(n * m)_ |  |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Easy | Two Pointers | [Python](./problems/remove_duplicates_from_sorted_array/remove_duplicates_from_sorted_array.py), [C++](./problems/remove_duplicates_from_sorted_array/remove_duplicates_from_sorted_array.cc) | _O(n)_ | _O(1)_ |  |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | Easy | Two Pointers | [Python](./problems/remove_element/remove_element.py), [C++](./problems/remove_element/remove_element.cc) | _O(n)_ | _O(1)_ |  |
| 28 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | Easy | Brute Force | [Python](./problems/find_the_index_of_the_first_occurrence_in_a_string/find_the_index_of_the_first_occurrence_in_a_string_brute_force.py), [C++](./problems/find_the_index_of_the_first_occurrence_in_a_string/find_the_index_of_the_first_occurrence_in_a_string_brute_force.cc) | _O(n * m)_ | _O(1)_ |  |
|  |  |  | Knuth-Morris-Pratt (KMP) Algorithm | [Python](./problems/find_the_index_of_the_first_occurrence_in_a_string/find_the_index_of_the_first_occurrence_in_a_string_kmp.py), [C++](./problems/find_the_index_of_the_first_occurrence_in_a_string/find_the_index_of_the_first_occurrence_in_a_string_kmp.cc) | _O(n + m)_ | _O(m)_ |  |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | Hard | Brute Force | [Python](./problems/trapping_rain_water/trapping_rain_water_brute_force.py), [C++](./problems/trapping_rain_water/trapping_rain_water_brute_force.cc) | _O(n^2)_ | _O(1)_ |  |
|  |  |  | Dynamic Programming | [Python](./problems/trapping_rain_water/trapping_rain_water_dynamic_programming.py), [C++](./problems/trapping_rain_water/trapping_rain_water_dynamic_programming.cc) | _O(n)_ | _O(n)_ |  |
|  |  |  | Monotonic Stack | [Python](./problems/trapping_rain_water/trapping_rain_water_monotonic_stack.py), [C++](./problems/trapping_rain_water/trapping_rain_water_monotonic_stack.cc) | _O(n)_ | _O(n)_ |  |
|  |  |  | Two Pointers | [Python](./problems/trapping_rain_water/trapping_rain_water_two_pointers.py), [C++](./problems/trapping_rain_water/trapping_rain_water_two_pointers.cc) | _O(n)_ | _O(1)_ |  |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | Medium | Dynamic Programming | [Python](./problems/jump_game_ii/jump_game_ii_dynamic_programming.py), [C++](./problems/jump_game_ii/jump_game_ii_dynamic_programming.cc) | _O(n^2)_ | _O(n)_ |  |
|  |  |  | Greedy | [Python](./problems/jump_game_ii/jump_game_ii_greedy.py), [C++](./problems/jump_game_ii/jump_game_ii_greedy.cc) | _O(n)_ | _O(1)_ |  |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | Medium | Dynamic Programming | [Python](./problems/jump_game/jump_game_dynamic_programming.py), [C++](./problems/jump_game/jump_game_dynamic_programming.cc) | _O(n^2)_ | _O(n)_ |  |
|  |  |  | Greedy | [Python](./problems/jump_game/jump_game_greedy.py), [C++](./problems/jump_game/jump_game_greedy.cc) | _O(n)_ | _O(1)_ |  |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | Easy | String Traversal | [Python](./problems/length_of_last_word/length_of_last_word.py), [C++](./problems/length_of_last_word/length_of_last_word.cc) | _O(n)_ | _O(1)_ |  |
| 68 | [Text Justification](https://leetcode.com/problems/text-justification/) | Hard | Greedy | [Python](./problems/text_justification/text_justification.py), [C++](./problems/text_justification/text_justification.cc) | _O(k * maxWidth), where k is the number of lines_ | _O(maxWidth)_ |  |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | Medium | Two Pointers | [Python](./problems/remove_duplicates_from_sorted_array_ii/remove_duplicates_from_sorted_array_ii.py), [C++](./problems/remove_duplicates_from_sorted_array_ii/remove_duplicates_from_sorted_array_ii.cc) | _O(n)_ | _O(1)_ |  |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | Easy | Two Pointers | [Python](./problems/merge_sorted_array/merge_sorted_array.py), [C++](./problems/merge_sorted_array/merge_sorted_array.cc) | _O(m + n)_ | _O(1)_ |  |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Easy | Dynamic Programming | [Python](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock_dynamic_programming.py), [C++](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock_dynamic_programming.cc) | _O(n)_ | _O(1)_ |  |
|  |  |  | Greedy | [Python](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock_greedy.py), [C++](./problems/best_time_to_buy_and_sell_stock/best_time_to_buy_and_sell_stock_greedy.cc) | _O(n)_ | _O(1)_ |  |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | Medium | Dynamic Programming | [Python](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii_dynamic_programming.py), [C++](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii_dynamic_programming.cc) | _O(n)_ | _O(1)_ |  |
|  |  |  | Greedy | [Python](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii_greedy.py), [C++](./problems/best_time_to_buy_and_sell_stock_ii/best_time_to_buy_and_sell_stock_ii_greedy.cc) | _O(n)_ | _O(1)_ |  |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | Medium | Greedy | [Python](./problems/gas_station/gas_station_greedy.py), [C++](./problems/gas_station/gas_station_greedy.cc) | _O(n)_ | _O(1)_ |  |
| 135 | [Candy](https://leetcode.com/problems/candy/) | Hard | Greedy (Two Passes) | [Python](./problems/candy/candy.py), [C++](./problems/candy/candy.cc) | _O(n)_ | _O(n)_ |  |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | Medium | In-Place Reversal | [Python](./problems/reverse_words_in_a_string/reverse_words_in_a_string_two_pointers.py), [C++](./problems/reverse_words_in_a_string/reverse_words_in_a_string_two_pointers.cc) | _O(n)_ | _O(1)_ |  |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/) | Easy | Boyer-Moore Majority Vote Algorithm | [Python](./problems/majority_element/majority_element.py), [C++](./problems/majority_element/majority_element.cc) | _O(n)_ | _O(1)_ |  |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | Medium | Repeated Shift | [Python](./problems/rotate_array/rotate_array_repeated_shift.py), [C++](./problems/rotate_array/rotate_array_repeated_shift.cc) | _O(nk)_ | _O(1)_ |  |
|  |  |  | Extra Space | [Python](./problems/rotate_array/rotate_array_extra_space.py), [C++](./problems/rotate_array/rotate_array_extra_space.cc) | _O(n)_ | _O(n)_ |  |
|  |  |  | Reversal | [Python](./problems/rotate_array/rotate_array_reversal.py), [C++](./problems/rotate_array/rotate_array_reversal.cc) | _O(n)_ | _O(1)_ |  |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | Prefix Sum | [Python](./problems/product_of_array_except_self/product_of_array_except_self.py), [C++](./problems/product_of_array_except_self/product_of_array_except_self.cc) | _O(n)_ | _O(1)_ |  |
| 274 | [H-Index](https://leetcode.com/problems/h-index/) | Medium | Sorting | [Python](./problems/h_index/h_index_sorting.py), [C++](./problems/h_index/h_index_sorting.cc) | _O(n log n)_ | _O(1)_ |  |
|  |  |  | Counting Sort | [Python](./problems/h_index/h_index_counting_sort.py), [C++](./problems/h_index/h_index_counting_sort.cc) | _O(n)_ | _O(n)_ |  |
| 380 | [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) | Medium | Array & Hashmap | [Python](./problems/insert_delete_getrandom_o1/insert_delete_getrandom_o1.py), [C++](./problems/insert_delete_getrandom_o1/insert_delete_getrandom_o1.cc) | _O(1)_ | _O(n)_ |  |

## Two Pointers

| # | Title | Difficulty | Approach | Solution | Time | Space | Note |
|---|-------|------------|----------|----------|------|-------|------|
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Easy | Two Pointers | [Python](./problems/valid_palindrome/valid_palindrome.py), [C++](./problems/valid_palindrome/valid_palindrome.cc) | _O(n)_ | _O(1)_ |  |

## Hashmap

| # | Title | Difficulty | Approach | Solution | Time | Space | Note |
|---|-------|------------|----------|----------|------|-------|------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy | Brute Force | [Python](./problems/two_sum/two_sum_brute_force.py), [C++](./problems/two_sum/two_sum_brute_force.cc) | _O(n^2)_ | _O(1)_ |  |
|  |  |  | Hash Map | [Python](./problems/two_sum/two_sum_hash_map.py), [C++](./problems/two_sum/two_sum_hash_map.cc) | _O(n)_ | _O(n)_ |  |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | Medium | — | [Python](./problems/group_anagrams/group_anagrams.py), [C++](./problems/group_anagrams/group_anagrams.cc) | _O(n * k log k)_ | _O(n)_ | For C++, the complexity is _O(n * k log k)_, where n is the number of strings and k is the maximum length of a string. But for Python, the complexity is _O(n * k)_ as there is no sorting involved. |

## Graph General

| # | Title | Difficulty | Approach | Solution | Time | Space | Note |
|---|-------|------------|----------|----------|------|-------|------|
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/) | Medium | — | [Python](./problems/evaluate_division/evaluate_division.py), [C++](./problems/evaluate_division/evaluate_division.cc) | _O(N + M)_ | _O(N)_ | N = number of equations, M = number of queries. |
