#!/usr/bin/env bash
set -euo pipefail

echo "Uninstalling Git hooks..."
rm -f .git/hooks/pre-commit
echo "Git hooks uninstalled."
