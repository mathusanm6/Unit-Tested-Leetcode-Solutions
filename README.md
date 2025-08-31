# 🧮 LeetCode Solutions

<div align="center">

### 🔬 Code Health & Testing

[![C++ Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/code-health-cpp.yml?branch=main&label=C%2B%2B%20Tests&logo=cplusplus&logoColor=white&style=for-the-badge)](https://github.com/mathusanm6/LeetCode/actions/workflows/code-health-cpp.yml)
[![Python Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/code-health-python.yml?branch=main&label=Python%20Tests&logo=python&logoColor=white&style=for-the-badge)](https://github.com/mathusanm6/LeetCode/actions/workflows/code-health-python.yml)

### 🔍 Code Quality & Linting

[![C++ Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/linter-cpp.yml?branch=main&label=C%2B%2B%20Linter&logo=cplusplus&logoColor=white&style=for-the-badge&color=blue)](https://github.com/mathusanm6/LeetCode/actions/workflows/linter-cpp.yml)
[![Python Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/linter-python.yml?branch=main&label=Python%20Linter&logo=python&logoColor=white&style=for-the-badge&color=blue)](https://github.com/mathusanm6/LeetCode/actions/workflows/linter-python.yml)

### 📊 Repository Stats

[![Last Commit](https://img.shields.io/github/last-commit/mathusanm6/LeetCode?style=for-the-badge&logo=git&logoColor=white)](https://github.com/mathusanm6/LeetCode/commits/main)
[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-3-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)
[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-3-green?style=for-the-badge&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)

</div>

## Description

This repository contains my solutions to LeetCode problems. I will be updating this repository with my solutions as I solve more problems. I have included a test suite for each solution.

## Running Tests

### Python Tests

To run the Python test suite, use the following commands in **the repository directory**:

```bash
# Run all Python tests
make test-py:all

# Run tests for a specific problem (e.g., two-sum)
make test-py:two-sum
```

### C++ Tests

To run the C++ test suite, use the following commands in the repository directory:

```bash
# Run all C++ tests
make test-cpp:all

# Run tests for a specific problem (e.g., two-sum)
make test-cpp:two-sum

# Run both C++ and Python tests for all problems
make test:all
```

## Code Quality

This project includes comprehensive code quality tools and automated linting:

### Linting and Formatting

```bash
# Format all code (C++ and Python)
make format

# Lint all code (C++ and Python)
make lint

# Format/lint specific languages
make format-cpp     # Format C++ files with clang-format
make format-python  # Format Python files with ruff
make lint-cpp       # Lint C++ files with clang-tidy
make lint-python    # Lint Python files with ruff
```

### Continuous Integration

- **Linters**: Automated code formatting and linting checks on every push/PR
- **Presubmit**: Comprehensive testing of changed files before merge
- **Postsubmit**: Full test suite execution after merge to main branch
- All workflows leverage the project's Makefile for consistency

## Algorithms

- [Arrays & Hashing](#arrays--hashing)
- [Two Pointers](#two-pointers)
- [Sliding Window](#sliding-window)
- [Stack](#stack)
- [Matrix](#matrix)
- [Intervals](#intervals)
- [Linked List](#linked-list)
- [Binary Tree General](#binary-tree-general)
- [Binary Tree BFS](#binary-tree-bfs)
- [Binary Search Tree](#binary-search-tree)
- [Graph General](#graph-general)
- [Dynamic Programming](#dynamic-programming)
- [Backtracking](#backtracking)
- [Heap](#heap)
- [Greedy](#greedy)
- [Trie](#trie)

## Arrays & Hashing

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [Python](./problems/two_sum/two_sum.py), [C++](./problems/two_sum/two_sum.cc) | _O(n)_ | _O(n)_ | Easy |  |  |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/) | [Python](./problems/contains_duplicate/contains_duplicate.py), [C++](./problems/contains_duplicate/contains_duplicate.cc) | _O(n)_ | _O(n)_ | Easy |  |  |

## Two Pointers

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [Python](./problems/valid_palindrome/valid_palindrome.py), [C++](./problems/valid_palindrome/valid_palindrome.cc) | _O(n)_ | _O(1)_ | Easy |  |  |

## License

This project is licensed under the MIT License - see the LICENSE file for details.
