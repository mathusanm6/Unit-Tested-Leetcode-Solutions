# LeetCode Solutions

<div align="center">

### Code Quality & Testing
[![C++](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/cpp.yml?branch=main&label=C%2B%2B&logo=cplusplus&logoColor=white&style=flat-square)](https://github.com/mathusanm6/LeetCode/actions/workflows/cpp.yml)
[![Python](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/python.yml?branch=main&label=Python&logo=python&logoColor=white&style=flat-square)](https://github.com/mathusanm6/LeetCode/actions/workflows/python.yml)

### Repository Stats

[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-32-blue?style=flat-square&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)
[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-32-blue?style=flat-square&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)

</div>

## Description

LeetCode problem solutions implemented in C++20 and Python 3, hermetically built and tested with [Bazel](https://bazel.build).

Each problem includes:
- Multiple approaches (e.g. brute force, two-pointer, greedy, dynamic programming) with time and space complexity notes
- Unit test coverage with GoogleTest (C++) and pytest (Python)
- Shared data structure implementations in `common/` (e.g. `TreeNode`, `ListNode`)

## Directory Layout

Each problem lives in its own directory under `problems/`:

```
problems/<problem_name>/
├── config.yml        # Metadata, difficulty, tags, and complexities
├── BUILD.bazel       # Bazel targets
├── <name>.cc         # C++ solution
├── <name>.h          # C++ header
├── <name>_test.cc    # GoogleTest suite
├── <name>.py         # Python solution
└── <name>_test.py    # pytest suite
```

## Testing

All tests run hermetically through Bazel:

```bash
# Run all tests
bazel test //problems/...

# Run all tests for a specific problem
bazel test //problems/two_sum:test

# Run tests by language
bazel test --test_tag_filters=cc //problems/...   # C++ (GoogleTest)
bazel test --test_tag_filters=py //problems/...   # Python (pytest)

# Run a single language target for a problem
bazel test //problems/two_sum:cc_test
bazel test //problems/two_sum:py_test
```

## Formatting & Linting

Formatting and linting use `clang-format` and `clang-tidy` for C++, and `ruff` for Python:

```bash
# Format code
./scripts/format.sh          # both C++ and Python
./scripts/format.sh cpp      # C++ only
./scripts/format.sh py       # Python only

# Lint code
./scripts/lint.sh            # both C++ and Python
./scripts/lint.sh cpp        # C++ only
./scripts/lint.sh py         # Python only
```

Pre-commit hooks can be installed to format, lint, and run tests before committing:

```bash
./scripts/install_hooks.sh
```

## Solutions

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
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Medium | Two Pointers | [Python](./problems/container_with_most_water/container_with_most_water.py), [C++](./problems/container_with_most_water/container_with_most_water.cc) | _O(n)_ | _O(1)_ |  |
| 15 | [3Sum](https://leetcode.com/problems/3sum/) | Medium | Sorting & Two Pointers | [Python](./problems/3sum/3sum.py), [C++](./problems/3sum/3sum.cc) | _O(n^2)_ | _O(1)_ | You have to avoid duplicates without using sets. |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Easy | Two Pointers | [Python](./problems/valid_palindrome/valid_palindrome.py), [C++](./problems/valid_palindrome/valid_palindrome.cc) | _O(n)_ | _O(1)_ |  |
| 167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Medium | Two Pointers | [Python](./problems/two_sum_ii_input_array_is_sorted/two_sum_ii_input_array_is_sorted.py), [C++](./problems/two_sum_ii_input_array_is_sorted/two_sum_ii_input_array_is_sorted.cc) | _O(n)_ | _O(1)_ |  |
| 392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | Easy | Two Pointers | [Python](./problems/is_subsequence/is_subsequence.py), [C++](./problems/is_subsequence/is_subsequence.cc) | _O(n)_ | _O(1)_ |  |

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
