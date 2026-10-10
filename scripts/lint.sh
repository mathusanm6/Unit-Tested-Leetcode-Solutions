#!/usr/bin/env bash
set -euo pipefail

# ANSI color codes
BLUE="\033[1;34m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
RESET="\033[0m"

TARGET="${1:-all}"
CXXFLAGS="-std=c++20 -Wall -Wextra -Wpedantic -Icommon -Iproblems"

lint_cpp() {
    echo -e "${BLUE}Linting C++ files...${RESET}"
    if command -v clang-tidy >/dev/null 2>&1; then
        find problems common -type f \( -name '*.cc' -o -name '*.h' \) -print0 | \
        xargs -0 -P 4 -I {} clang-tidy {} --config-file=.clang-tidy --quiet --header-filter="^(problems|common)/.*\\.(h|cc)$" -- ${CXXFLAGS} -x c++ 2>/dev/null | \
        grep -E "^[^:]+:[0-9]+:[0-9]+:" || true
        echo -e "${GREEN}C++ linting complete.${RESET}"
    else
        echo -e "${RED}clang-tidy not found. Please install it to lint C++ files.${RESET}"
        return 1
    fi
}

lint_py() {
    echo -e "${BLUE}Linting Python files...${RESET}"
    if command -v ruff >/dev/null 2>&1; then
        ruff check problems common scripts
        echo -e "${GREEN}Python linting complete with ruff.${RESET}"
    elif [ -x ".venv/bin/ruff" ]; then
        .venv/bin/ruff check problems common scripts
        echo -e "${GREEN}Python linting complete with .venv ruff.${RESET}"
    elif command -v flake8 >/dev/null 2>&1; then
        find problems common scripts -name '*.py' | xargs flake8
        echo -e "${GREEN}Python linting complete with flake8.${RESET}"
    else
        echo -e "${RED}Neither ruff nor flake8 found. Please install one of them to lint Python files.${RESET}"
        return 1
    fi
}

case "$TARGET" in
    cpp)
        lint_cpp
        ;;
    py|python)
        lint_py
        ;;
    all)
        lint_cpp
        echo ""
        lint_py
        ;;
    *)
        echo -e "${RED}Unknown target: $TARGET. Use: all, cpp, or py${RESET}"
        exit 1
        ;;
esac
