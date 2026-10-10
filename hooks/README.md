# Git Hooks

This directory contains Git hooks that can be installed to maintain code quality.

## Available Hooks

### pre-commit

The pre-commit hook ensures code quality by running the following checks before allowing any commit:

1. **Badge Updates and README Check** - Automatically updates README badges and verifies `README.md` via `bazel run //scripts:generate_readme`
2. **Code Formatting** - Formats C++ and Python files using `./scripts/format.sh` (`clang-format` and `ruff`)
3. **Code Linting** - Lints C++ and Python files using `./scripts/lint.sh` (`clang-tidy` and `ruff`)
4. **Tests** - Runs test suites via `bazel test //problems/...`

## Installation

To install the hooks, run:

```bash
./scripts/install_hooks.sh
```

To uninstall the hooks, run:

```bash
./scripts/uninstall_hooks.sh
```

## Manual Installation

If you prefer to install manually:

```bash
cp hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

## More Information

See [`../.github/PRE_COMMIT_HOOK.md`](../.github/PRE_COMMIT_HOOK.md) for detailed documentation about the pre-commit hook functionality and troubleshooting.
