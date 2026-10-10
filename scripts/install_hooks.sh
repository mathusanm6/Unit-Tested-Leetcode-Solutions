#!/usr/bin/env bash
set -euo pipefail

echo "Installing Git hooks..."
cp hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
echo "Git hooks installed successfully."
