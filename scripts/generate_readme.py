#!/usr/bin/env python3
"""
README Generator for LeetCode Solutions
Generates the problems table from individual problem configuration files.
"""

import os
import yaml
import argparse
from pathlib import Path
from typing import Dict, List, Any
from collections import defaultdict


class Colors:
    """ANSI color codes matching the Makefile color functions."""

    BLUE = "\033[1;34m"
    GREEN = "\033[1;32m"
    YELLOW = "\033[1;33m"
    RED = "\033[1;31m"
    CYAN = "\033[1;36m"
    RESET = "\033[0m"

    @staticmethod
    def blue(text: str) -> str:
        return f"{Colors.BLUE}{text}{Colors.RESET}"

    @staticmethod
    def green(text: str) -> str:
        return f"{Colors.GREEN}{text}{Colors.RESET}"

    @staticmethod
    def yellow(text: str) -> str:
        return f"{Colors.YELLOW}{text}{Colors.RESET}"

    @staticmethod
    def red(text: str) -> str:
        return f"{Colors.RED}{text}{Colors.RESET}"

    @staticmethod
    def cyan(text: str) -> str:
        return f"{Colors.CYAN}{text}{Colors.RESET}"


class ReadmeGenerator:
    def __init__(self, root_dir: str = "."):
        self.root_dir = Path(root_dir)
        self.config_dir = self.root_dir / "config"
        self.problems_dir = self.root_dir / "problems"

    def load_config(self, config_file: str) -> Dict[str, Any]:
        """Load YAML configuration file."""
        config_path = self.config_dir / config_file
        if not config_path.exists():
            return {}

        with open(config_path, "r") as f:
            return yaml.safe_load(f)

    def find_problem_configs(self) -> List[Path]:
        """Find all problem configuration files."""
        config_files = []
        for root, dirs, files in os.walk(self.problems_dir):
            if "config.yml" in files:
                config_files.append(Path(root) / "config.yml")
        return config_files

    def load_problem_config(self, config_path: Path) -> Dict[str, Any]:
        """Load a single problem configuration."""
        with open(config_path, "r") as f:
            return yaml.safe_load(f)

    def validate_problem_config(self, config: Dict[str, Any]) -> bool:
        """Validate problem configuration against allowed values."""
        difficulties = self.load_config("difficulties.yml").get("difficulties", [])
        tags = self.load_config("tags.yml").get("tags", [])

        problem = config.get("problem", {})

        # Validate difficulty
        if problem.get("difficulty") not in difficulties:
            print(
                Colors.red(
                    f"✗ Invalid difficulty '{problem.get('difficulty')}' in problem {problem.get('number')}"
                )
            )
            return False

        # Validate tags
        problem_tags = problem.get("tags", [])
        for tag in problem_tags:
            if tag not in tags:
                print(
                    Colors.red(
                        f"✗ Invalid tag '{tag}' in problem {problem.get('number')}"
                    )
                )
                return False

        return True

    def generate_anchor(self, tag: str) -> str:
        """Generate a markdown anchor from a tag name."""
        return tag.lower().replace(" ", "-").replace("&", "")

    def format_solutions(self, solutions: Dict[str, str]) -> str:
        """Format solution links for the table."""
        formatted_solutions = []
        for lang, path in solutions.items():
            lang_display = "C++" if lang == "cpp" else lang.capitalize()
            formatted_solutions.append(f"[{lang_display}](./{path})")
        return ", ".join(formatted_solutions)

    def generate_table_of_contents(self) -> str:
        """Generate table of contents for algorithms section."""
        tags = self.load_config("tags.yml").get("tags", [])
        toc_items = []

        for tag in tags:
            tag_anchor = self.generate_anchor(tag)
            toc_items.append(f"- [{tag}](#{tag_anchor})")

        return "\n".join(toc_items)

    def generate_problems_table(self) -> str:
        """Generate the problems table organized by tags."""
        config_files = self.find_problem_configs()
        problems_by_tag = defaultdict(list)

        # Load and organize problems by tag
        for config_path in config_files:
            try:
                config = self.load_problem_config(config_path)
                if not self.validate_problem_config(config):
                    continue

                problem = config["problem"]
                for tag in problem.get("tags", ["Uncategorized"]):
                    problems_by_tag[tag].append(config)
            except Exception as e:
                print(Colors.red(f"✗ Error loading {config_path}: {e}"))
                continue

        # Generate markdown
        markdown_sections = []

        # Only include tags that have problems
        available_tags = self.load_config("tags.yml").get("tags", [])
        for tag in available_tags:
            if tag not in problems_by_tag:
                continue

            problems = sorted(
                problems_by_tag[tag], key=lambda x: x["problem"]["number"]
            )

            # Create section header
            tag_anchor = self.generate_anchor(tag)
            markdown_sections.append(f"## {tag}")
            markdown_sections.append("")

            # Create table header
            table_header = (
                "| # | Title | Solution | Time | Space | Difficulty | Tag | Note |"
            )
            table_divider = (
                "|---|-------|----------|------|-------|------------|-----|------|"
            )
            markdown_sections.extend([table_header, table_divider])

            # Add problem rows
            for config in problems:
                problem = config["problem"]
                solutions = config.get("solutions", {})
                complexity = config.get("complexity", {})

                # Format the row
                number = problem["number"]
                title = f"[{problem['title']}]({problem['leetcode_url']})"
                solution_links = self.format_solutions(solutions)
                time_complexity = f"_{complexity.get('time', 'N/A')}_"
                space_complexity = f"_{complexity.get('space', 'N/A')}_"
                difficulty = problem["difficulty"].capitalize()
                tags_display = ""  # Could show additional tags if needed
                notes = config.get("notes", "")

                # Add readme link if available
                if config.get("readme_link"):
                    if notes:
                        notes += f" [Details]({config['readme_link']})"
                    else:
                        notes = f"[Details]({config['readme_link']})"

                row = f"| {number} | {title} | {solution_links} | {time_complexity} | {space_complexity} | {difficulty} | {tags_display} | {notes} |"
                markdown_sections.append(row)

            markdown_sections.append("")

        return "\n".join(markdown_sections)

    def update_readme(self, readme_path: str = "README.md"):
        """Update the README file with generated problems table."""
        readme_file = self.root_dir / readme_path

        if not readme_file.exists():
            print(Colors.red(f"✗ README file {readme_file} not found!"))
            return

        print("Generating README from problem configurations...")

        # Read current README
        with open(readme_file, "r") as f:
            content = f.read()

        # Generate new problems table
        toc = self.generate_table_of_contents()
        problems_table = self.generate_problems_table()

        # Find the algorithms section
        start_marker = "## 🧮 Algorithms & Data Structures"

        start_idx = content.find(start_marker)

        if start_idx == -1:
            print(
                Colors.red(
                    "✗ Could not find '🧮 Algorithms & Data Structures' section in README"
                )
            )
            return

        # Look for the end of the algorithms content
        # We need to find either:
        # 1. The next top-level section that's NOT a tag section (## but not a tag name)
        # 2. End of file if no such section exists

        available_tags = self.load_config("tags.yml").get("tags", [])

        # Start searching after the "## Algorithms" line
        search_start = start_idx + len(start_marker)

        # Find all "## " occurrences after the algorithms section
        end_idx = len(content)  # Default to end of file
        pos = search_start

        while True:
            next_section = content.find("\n## ", pos)
            if next_section == -1:
                # No more sections found
                break

            # Extract the section title (everything after "## " until newline)
            section_start = next_section + 4  # Skip "\n## "
            section_end = content.find("\n", section_start)
            if section_end == -1:
                section_title = content[section_start:].strip()
            else:
                section_title = content[section_start:section_end].strip()

            # Check if this section title is NOT one of our algorithm tags
            if section_title not in available_tags:
                # This is a non-algorithm section, so algorithms content ends here
                end_idx = next_section
                break

            # Continue searching after this section
            pos = next_section + 1

        # Preserve content after the algorithms section
        content_after = content[end_idx:] if end_idx < len(content) else ""

        # Replace only the algorithms section
        new_algorithms_section = f"## 🧮 Algorithms & Data Structures\n\nThis repository covers a comprehensive range of algorithmic patterns and data structures commonly found in technical interviews:\n\n{toc}\n\n{problems_table}"

        new_content = content[:start_idx] + new_algorithms_section + content_after

        # Write updated README
        with open(readme_file, "w") as f:
            f.write(new_content)

        # Show statistics
        config_files = self.find_problem_configs()
        valid_configs = 0
        for config_path in config_files:
            try:
                config = self.load_problem_config(config_path)
                if self.validate_problem_config(config):
                    valid_configs += 1
            except (yaml.YAMLError, FileNotFoundError, Exception):
                pass

        print(Colors.green("✓ README updated successfully!"))
        print(Colors.green(f"  Processed {valid_configs} valid problem configurations"))


def main():
    parser = argparse.ArgumentParser(
        description="Generate README from problem configurations"
    )
    parser.add_argument("--root", default=".", help="Root directory of the project")
    parser.add_argument("--readme", default="README.md", help="README file path")
    parser.add_argument("--verbose", "-v", action="store_true", help="Verbose output")

    args = parser.parse_args()

    if args.verbose:
        print(Colors.blue("=== LeetCode README Generator ==="))
        print(Colors.yellow(f"Root directory: {args.root}"))
        print(Colors.yellow(f"README file: {args.readme}"))
        print("")

    generator = ReadmeGenerator(args.root)
    generator.update_readme(args.readme)


if __name__ == "__main__":
    main()
