#!/usr/bin/env python3
"""
Script to automatically update README badges with current problem counts.
This script counts the number of solved problems in each language and updates the README.md file.
"""

import os
import re
from pathlib import Path


def count_cpp_problems():
    """Count C++ problems in the problems directory."""
    problems_dir = Path("problems")
    if not problems_dir.exists():
        return 0

    cpp_count = 0
    for problem_dir in problems_dir.iterdir():
        if problem_dir.is_dir():
            # Check if this problem has C++ files
            cpp_files = list(problem_dir.glob("*.cc")) + list(problem_dir.glob("*.cpp"))
            if cpp_files:
                cpp_count += 1

    return cpp_count


def count_python_problems():
    """Count Python problems in the problems directory."""
    problems_dir = Path("problems")
    if not problems_dir.exists():
        return 0

    python_count = 0
    for problem_dir in problems_dir.iterdir():
        if problem_dir.is_dir():
            # Check if this problem has Python files
            python_files = list(problem_dir.glob("*.py"))
            if python_files:
                python_count += 1

    return python_count


def update_readme_badges(cpp_count, python_count):
    """Update the README.md file with new badge counts."""
    readme_path = Path("README.md")
    if not readme_path.exists():
        print("ERROR: README.md not found!")
        return False

    # Read the current README content
    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    # Define the new badge lines
    cpp_badge = f"[![C++ Solutions](https://img.shields.io/badge/C%2B%2B%20Solutions-{cpp_count}-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)"
    python_badge = f"[![Python Solutions](https://img.shields.io/badge/Python%20Solutions-{python_count}-blue?style=for-the-badge&logo=python&logoColor=white)](https://github.com/mathusanm6/LeetCode/tree/main/problems)"

    # Update C++ badge
    cpp_pattern = r"\[\!\[C\+\+ Solutions\].*?\)\]\(.*?\)"
    if re.search(cpp_pattern, content):
        content = re.sub(cpp_pattern, cpp_badge, content)
    else:
        print("WARNING: C++ badge pattern not found in README.md")

    # Update Python badge
    python_pattern = r"\[\!\[Python Solutions\].*?\)\]\(.*?\)"
    if re.search(python_pattern, content):
        content = re.sub(python_pattern, python_badge, content)
    else:
        print("WARNING: Python badge pattern not found in README.md")

    # Write the updated content back
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(content)

    return True


def main():
    """Main function to count problems and update badges."""
    print("🔍 Counting solved problems...")

    # Count problems in each language
    cpp_count = count_cpp_problems()
    python_count = count_python_problems()

    print(f"📊 Found {cpp_count} C++ problems")
    print(f"📊 Found {python_count} Python problems")

    # Update the README
    if update_readme_badges(cpp_count, python_count):
        print("✅ README.md badges updated successfully!")
        print(f"   C++ Solutions: {cpp_count}")
        print(f"   Python Solutions: {python_count}")
    else:
        print("❌ Failed to update README.md")
        return 1

    return 0


if __name__ == "__main__":
    # Change to the repository root directory
    script_dir = Path(__file__).parent
    repo_root = script_dir.parent
    os.chdir(repo_root)

    exit(main())
