# Pre-commit Hook Configuration

This repository uses a pre-commit hook to ensure code quality and prevent broken commits.

## What the pre-commit hook does

The pre-commit hook automatically runs the following checks before allowing any commit:

1. **Badge Updates and README Check** (`./scripts/update_badges.sh` and `bazel run //scripts:generate_readme`)
   - Automatically updates README badges when problem files are modified
   - Ensures README.md is up to date with current problem counts
   - Automatically stages updated README.md if badges are modified

2. **Code Formatting** (`./scripts/format.sh`)
   - Formats C++ files using `clang-format`
   - Formats Python files using `ruff` (or `black` as fallback)
   - Automatically stages formatted files if changes are made

3. **Code Linting** (`./scripts/lint.sh`)
   - Lints C++ files using `clang-tidy`
   - Lints Python files using `ruff` (or `flake8` as fallback)

4. **Tests** (`bazel test //problems/...`)
   - Runs all C++ tests using Google Test hermetically via Bazel
   - Runs all Python tests using pytest hermetically via Bazel

## Installation

The pre-commit hook needs to be installed after cloning the repository:

```bash
./scripts/install_hooks.sh
```

To uninstall the hooks (if needed), run:

```bash
./scripts/uninstall_hooks.sh
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

## Troubleshooting

### Hook fails on badge updates
- The hook automatically updates badges when problem files are modified:
  ```bash
  bazel run //scripts:update_badges
  # or: ./scripts/update_badges.sh
  ```

### Hook fails on formatting
- Run the formatter manually to see and apply changes:
  ```bash
  ./scripts/format.sh
  ```

### Hook fails on linting
- Fix the linting issues reported by running:
  ```bash
  ./scripts/lint.sh
  ```

### Hook fails on tests
- Run the tests with detailed output:
  ```bash
  bazel test //problems/... --test_output=errors
  ```
