#!/usr/bin/env bash
set -euo pipefail

# ANSI color codes
BLUE="\033[1;34m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
RESET="\033[0m"

TARGET="${1:-all}"

# Find Google Test include path if available on the system
GTEST_INC=""
if [ -d "/usr/include/gtest" ]; then
    GTEST_INC="-I/usr/include"
elif [ -d "/usr/local/include/gtest" ]; then
    GTEST_INC="-I/usr/local/include"
elif command -v brew >/dev/null 2>&1 && brew --prefix googletest >/dev/null 2>&1; then
    GTEST_INC="-I$(brew --prefix googletest)/include"
fi

CXXFLAGS="-std=c++20 -Wall -Wextra -Wpedantic -Icommon -Iproblems ${GTEST_INC}"

lint_cpp() {
    echo -e "${BLUE}Linting C++ files...${RESET}"

    CLANG_TIDY=""
    if command -v clang-tidy >/dev/null 2>&1; then
        CLANG_TIDY="clang-tidy"
    elif [ -x "/opt/homebrew/opt/llvm/bin/clang-tidy" ]; then
        CLANG_TIDY="/opt/homebrew/opt/llvm/bin/clang-tidy"
    elif [ -x "/usr/local/opt/llvm/bin/clang-tidy" ]; then
        CLANG_TIDY="/usr/local/opt/llvm/bin/clang-tidy"
    fi

    if [ -z "$CLANG_TIDY" ]; then
        echo -e "${RED}clang-tidy not found.${RESET}"
        echo -e "${YELLOW}macOS:${RESET} Install via Homebrew: ${BLUE}brew install llvm${RESET}"
        echo -e "${YELLOW}       ${RESET}Then add to PATH:       ${BLUE}export PATH=\"\$(brew --prefix llvm)/bin:\$PATH\"${RESET}"
        echo -e "${YELLOW}Linux:${RESET} Install via apt:      ${BLUE}sudo apt-get install -y clang-tidy${RESET}"
        return 1
    fi

    echo -e "Using: $($CLANG_TIDY --version | head -n 1)"

    # Only lint solution implementation files.
    # Header files (.h) are checked via --header-filter in their inclusion context (preventing #pragma once false positives).
    # Test files (*_test.cc) are excluded to prevent GoogleTest macro expansion warnings (TEST_P, INSTANTIATE_TEST_SUITE_P).
    local error_count=0
    while IFS= read -r -d '' file; do
        output=$("$CLANG_TIDY" "$file" --config-file=.clang-tidy --quiet \
            --header-filter="^(problems|common)/.*\\.(h|cc)$" \
            -- ${CXXFLAGS} -x c++ 2>&1 || true)
        
        # Filter for actual warnings/errors matching the file
        filtered=$(echo "$output" | grep -E "^[^:]+:[0-9]+:[0-9]+: (warning|error):" || true)
        if [ -n "$filtered" ]; then
            echo -e "${YELLOW}$file:${RESET}"
            echo "$filtered"
            error_count=$((error_count + 1))
        fi
    done < <(find problems common -type f -name '*.cc' -not -name '*_test.cc' -print0)

    if [ "$error_count" -gt 0 ]; then
        echo -e "${RED}C++ linting found issues in $error_count file(s).${RESET}"
        return 1
    fi

    echo -e "${GREEN}C++ linting complete. No issues found.${RESET}"
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
