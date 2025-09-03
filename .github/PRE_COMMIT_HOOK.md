# Pre-commit Hook Configuration

This repository uses a pre-commit hook to ensure code quality and prevent broken commits.

## What the pre-commit hook does

The pre-commit hook automatically runs the following checks before allowing any commit:

1. **Badge Updates and README Check** (`make update-badges` and `make readme-check`)

   - Automatically updates README badges when problem files are modified
   - Ensures README.md is up to date with current problem counts
   - Automatically stages updated README.md if badges are modified

2. **Code Formatting** (`make format`)

   - Formats C++ files using `clang-format`
   - Formats Python files using `ruff` (or `black` as fallback)
   - Automatically stages formatted files if changes are made

3. **Code Linting** (`make lint`)

   - Lints C++ files using `clang-tidy`
   - Lints Python files using `ruff` (or `flake8` as fallback)

4. **Tests** (`make test:all`)
   - Runs all C++ tests using Google Test
   - Runs all Python tests using pytest

## Installation

The pre-commit hook needs to be installed after cloning the repository. To install the hook, run:

```bash
make install-hooks
```

This will copy the pre-commit hook from the `hooks/` directory to `.git/hooks/` and make it executable.

To uninstall the hooks (if needed), run:

```bash
make uninstall-hooks
```

## Manual Testing

You can manually test the pre-commit hook by running:

```bash
./.git/hooks/pre-commit
```

## Bypassing the hook (not recommended)

If you absolutely need to bypass the pre-commit hook (e.g., for a work-in-progress commit), you can use:

```bash
git commit --no-verify -m "your commit message"
```

**Warning:** This is not recommended as it can introduce broken code into the repository.

## Troubleshooting

### Hook fails on badge updates

- The hook automatically updates badges when problem files are modified
- If badge update fails, check that you have Python 3 installed and the required dependencies:
  ```bash
  pip install -r requirements.txt
  ```
- Ensure the `scripts/update_badges.py` script is executable and working:
  ```bash
  make update-badges
  ```

### Hook fails on formatting

- The hook automatically fixes formatting issues and stages the corrected files
- If formatting fails, check that you have the required tools installed:
  - C++: `clang-format`
  - Python: `ruff` or `black`

### Hook fails on linting

- Fix the linting issues reported by running `make lint` to see details
- Common issues include:
  - Unused variables
  - Code style violations
  - Missing includes

### Hook fails on tests

- Fix the failing tests by running `make test:all` to see details
- Ensure all new code has corresponding tests
- Verify that existing functionality wasn't broken

### Installing required tools

For macOS (using Homebrew):

```bash
# C++ tools
brew install clang-format llvm

# Python tools (if not using requirements.txt)
pip install ruff pytest

# Google Test (for C++ tests)
brew install googletest
```

For Ubuntu/Debian:

```bash
# C++ tools
sudo apt-get install clang-format clang-tidy

# Python tools (if not using requirements.txt)
pip install ruff pytest

# Google Test (for C++ tests)
sudo apt-get install libgtest-dev
```

## Configuration

The pre-commit hook uses the existing Makefile targets. To modify the behavior:

1. **Badge updates**: Modify the `update-badges` target in `Makefile` or the `scripts/update_badges.py` script
2. **README checks**: Modify the `readme-check` and `readme` targets in `Makefile`
3. **Formatting rules**: Modify the `format-cpp` and `format-python` targets in `Makefile`
4. **Linting rules**: Modify the `lint-cpp` and `lint-python` targets in `Makefile`
5. **Test configuration**: Modify the `test:all` target in `Makefile`

## Benefits

- **Up-to-date documentation**: README badges are automatically updated when problems are added or modified
- **Consistent code style**: All code follows the same formatting standards
- **Early error detection**: Linting catches potential issues before they reach the repository
- **Reliable codebase**: Tests ensure that new changes don't break existing functionality
- **Team productivity**: Reduces time spent on code review for style and basic issues
- **Automated maintenance**: No need for separate CI workflows for badge updates
