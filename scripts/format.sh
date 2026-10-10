#!/usr/bin/env bash
set -euo pipefail

# ANSI color codes
BLUE="\033[1;34m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
RESET="\033[0m"

TARGET="${1:-all}"

format_cpp() {
    echo -e "${BLUE}Formatting C++ files...${RESET}"
    if command -v clang-format >/dev/null 2>&1; then
        find common problems -name '*.cc' -o -name '*.h' | xargs clang-format -i
        echo -e "${GREEN}C++ files formatted.${RESET}"
    elif [ -x "/Library/Developer/CommandLineTools/usr/bin/clang-format" ]; then
        find common problems -name '*.cc' -o -name '*.h' | xargs /Library/Developer/CommandLineTools/usr/bin/clang-format -i
        echo -e "${GREEN}C++ files formatted with Xcode clang-format.${RESET}"
    else
        echo -e "${RED}clang-format not found. Please install it to format C++ files.${RESET}"
        return 1
    fi
}

format_py() {
    echo -e "${BLUE}Formatting Python files...${RESET}"
    if command -v ruff >/dev/null 2>&1; then
        ruff format problems common scripts
        echo -e "${GREEN}Python files formatted with ruff.${RESET}"
    elif [ -x ".venv/bin/ruff" ]; then
        .venv/bin/ruff format problems common scripts
        echo -e "${GREEN}Python files formatted with .venv ruff.${RESET}"
    elif command -v black >/dev/null 2>&1; then
        find problems common scripts -name '*.py' | xargs black
        echo -e "${GREEN}Python files formatted with black.${RESET}"
    else
        echo -e "${RED}Neither ruff nor black found. Please install one of them to format Python files.${RESET}"
        return 1
    fi
}

case "$TARGET" in
    cpp)
        format_cpp
        ;;
    py|python)
        format_py
        ;;
    all)
        format_cpp
        echo ""
        format_py
        ;;
    *)
        echo -e "${RED}Unknown target: $TARGET. Use: all, cpp, or py${RESET}"
        exit 1
        ;;
esac
