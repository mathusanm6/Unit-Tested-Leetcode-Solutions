# Git Hooks

This directory contains Git hooks that can be installed to maintain code quality.

## Available Hooks

### pre-commit

The pre-commit hook ensures code quality by running the following checks before allowing any commit:

1. **Badge Updates and README Check** - Automatically updates README badges when problem files are modified
2. **Code Formatting** - Formats C++ and Python files using clang-format and ruff
3. **Code Linting** - Lints C++ and Python files using clang-tidy and ruff
4. **Tests** - Runs all tests to ensure code functionality

## Installation

To install the hooks, run:

```bash
make install-hooks
```

To uninstall the hooks, run:

```bash
make uninstall-hooks
```

## Manual Installation

If you prefer to install manually:

```bash
cp hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

## More Information

See [`../.github/PRE_COMMIT_HOOK.md`](../.github/PRE_COMMIT_HOOK.md) for detailed documentation about the pre-commit hook functionality and troubleshooting.
