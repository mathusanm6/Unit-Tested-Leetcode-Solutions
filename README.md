# Unit-Tested LeetCode Solutions

<div align="center">

### 🔬 Code Health & Testing

[![C++ Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/code-health-cpp.yml?branch=main&label=C%2B%2B%20Tests&logo=cplusplus&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/code-health-cpp.yml)
[![Python Tests](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/code-health-python.yml?branch=main&label=Python%20Tests&logo=python&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/code-health-python.yml)

### 🔍 Code Quality & Linting

[![C++ Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/linter-cpp.yml?branch=main&label=C%2B%2B%20Linter&logo=cplusplus&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/linter-cpp.yml)
[![Python Linter](https://img.shields.io/github/actions/workflow/status/mathusanm6/LeetCode/linter-python.yml?branch=main&label=Python%20Linter&logo=python&logoColor=white&style=for-the-badge&successColor=green&failureColor=red)](https://github.com/mathusanm6/LeetCode/actions/workflows/linter-python.yml)

### 📊 Repository Stats

[![Last Commit](https://img.shields.io/github/last-commit/mathusanm6/LeetCode?style=for-the-badge&logo=git&logoColor=white&color=blue)](https://github.com/mathusanm6/LeetCode/commits/main)
[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-8-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)
[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-8-blue?style=for-the-badge&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)

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
│   ├── two_sum/                 # Individual problem directories
│   │   ├── config.yml           # Problem metadata and configuration
│   │   ├── two_sum.py           # Python solution
│   │   ├── two_sum.cc           # C++ solution
│   │   ├── two_sum.h            # C++ header
│   │   ├── two_sum_test.py      # Python unit tests
│   │   └── two_sum_test.cc      # C++ unit tests
│   └── ...
├── config/                      # Global configuration files
│   ├── difficulties.yml         # Difficulty level definitions
│   └── tags.yml                 # Problem tag categories
├── scripts/                     # Automation and utility scripts
│   ├── generate_readme.py       # Auto-generate README content
│   ├── update_badges.py         # Update repository badges
│   └── update_badges.sh         # Badge update automation
├── .github/workflows/           # CI/CD automation
│   ├── code-health-*.yml        # Comprehensive testing workflows
│   ├── linter-*.yml             # Code quality workflows
│   ├── presubmit-*.yml          # Pre-merge validation
│   └── update-badges.yml        # Automated badge updates
├── Makefile                     # Build and test automation
├── requirements.txt             # Python dependencies
├── .clang-format                # C++ code formatting rules
└── .clang-tidy                  # C++ linting configuration
```

## 🛠️ Technologies & Tools

### Languages & Standards

- **C++**: C++20 with modern features and best practices
- **Python**: Python 3.x with type hints and modern syntax

### Testing Frameworks

- **C++**: Google Test (gtest) for comprehensive unit testing
- **Python**: pytest with coverage reporting

### Code Quality Tools

- **C++ Formatting**: clang-format for consistent code style
- **C++ Linting**: clang-tidy for static analysis and best practices
- **Python Formatting**: ruff for fast, comprehensive code formatting
- **Python Linting**: ruff for linting, import sorting, and code quality

### Build & Automation

- **Make**: Cross-platform build system with intelligent target detection
- **GitHub Actions**: Automated CI/CD with parallel testing and validation

## Running Tests

The project includes comprehensive test suites for all solutions with cross-platform support.

### 🐍 Python Tests

```bash
# Run all Python tests with coverage
make test-py:all

# Run tests for a specific problem (e.g., two-sum)
make test-py:two-sum
```

### ⚡ C++ Tests

```bash
# Run all C++ tests (auto-detects macOS/Linux)
make test-cpp:all

# Run tests for a specific problem (e.g., two-sum)
make test-cpp:two-sum

# Run all tests (both languages)
make test:all
```

**Requirements:**

- **macOS**: `brew install googletest`
- **Linux**: `sudo apt-get install libgtest-dev` or build from source

## Code Quality

This project maintains high code quality standards through automated tooling and CI/CD integration.

### 🎨 Formatting & Linting

```bash
# Format all code (C++ with clang-format, Python with ruff)
make format

# Lint all code with comprehensive checks
make lint

# Language-specific operations
make format-cpp     # Format C++ files with clang-format
make format-py  # Format Python files with ruff
make lint-cpp       # Lint C++ files with clang-tidy
make lint-py    # Lint Python files with ruff
```

### 🔄 Continuous Integration

The project includes a comprehensive CI/CD pipeline:

- **🔍 Presubmit Checks**: Validate code changes before merge
  - Format validation (clang-format, ruff)
  - Linting checks (clang-tidy, ruff)
  - Unit test execution for changed files
- **🧪 Code Health**: Full validation after merge to main

  - Complete test suite execution
  - Cross-platform compatibility testing
  - Coverage reporting

- **📊 Automated Maintenance**:
  - Badge updates reflecting current status
  - PR size labeling for review optimization
  - Workflow status monitoring

All workflows leverage the project's Makefile for consistency across local development and CI environments.

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
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | [Python](./problems/group_anagrams/group_anagrams.py), [C++](./problems/group_anagrams/group_anagrams.cc) | _O(n * k log k)_ | _O(n)_ | Medium |  | For C++, the complexity is _O(n * k log k)_, where n is the number of strings and k is the maximum length of a string. But for Python, the complexity is _O(n * k)_ as there is no sorting involved. |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [Python](./problems/contains_duplicate/contains_duplicate.py), [C++](./problems/contains_duplicate/contains_duplicate.cc) | _O(n)_ | _O(n)_ | Easy |  |  |
| 2303 | [Calculate Amount Paid In Taxes](https://leetcode.com/problems/calculate-amount-paid-in-taxes/) | [Python](./problems/calculate_amount_paid_in_taxes/calculate_amount_paid_in_taxes.py), [C++](./problems/calculate_amount_paid_in_taxes/calculate_amount_paid_in_taxes.cc) | _O(n)_ | _O(1)_ | Easy |  |  |

## Two Pointers

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [Python](./problems/valid_palindrome/valid_palindrome.py), [C++](./problems/valid_palindrome/valid_palindrome.cc) | _O(n)_ | _O(1)_ | Easy |  |  |

## Trees

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 2313 | [Minimum Flips in Binary Tree to Get Result](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result/) | [Python](./problems/minimum_flips_in_binary_tree_to_get_result/minimum_flips_in_binary_tree_to_get_result.py), [C++](./problems/minimum_flips_in_binary_tree_to_get_result/minimum_flips_in_binary_tree_to_get_result.cc) | _O(n)_ | _O(1)_ | Hard |  | _n_ is the number of nodes in the binary tree. |

## Backtracking

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 1087 | [Brace Expansion](https://leetcode.com/problems/brace-expansion/) | [Python](./problems/brace_expansion/brace_expansion.py), [C++](./problems/brace_expansion/brace_expansion.cc) | _O(M^K + M log M)_ | _O(M^K)_ | Medium |  | M = max choices per brace set, K = number of brace sets. M^K for generating combinations, M log M for sorting. |

## Graphs

| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---|-------|----------|------|-------|------------|-----|------|
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/) | [Python](./problems/evaluate_division/evaluate_division.py), [C++](./problems/evaluate_division/evaluate_division.cc) | _O(N + M)_ | _O(N)_ | Medium |  | N = number of equations, M = number of queries. |
