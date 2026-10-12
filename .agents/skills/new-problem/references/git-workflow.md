# Git workflow

Only follow this when the user asks for a commit/push/PR.

**IMPORTANT — Sandbox rule:** Every command below (`git checkout -b`, `git add`, `git commit`, `git push`, `gh pr create`) writes to `.git/` or uses network/pyenv hooks that are blocked by the sandbox. **Always run all of these commands directly with `BypassSandbox: true`** — never attempt them with `BypassSandbox: false` first.

- Branch naming: `feat-<number>-<PascalCaseTitle>` (e.g. `feat-27-Remove-Element`, `feat-88-Merge-Sorted-Array`).
- Files to stage: `README.md` and `problems/<snake_case_title>/` (plus any shared utilities in `common/` if added).
- Commit message: `feat: solve <number>. <Title> with unit testing`.
- Push: `git push -u origin <branch_name>`.
- Pull request title: `Adds <number>. <Title> with unit testing` (e.g. `Adds 88. Merge Sorted Array with unit testing`).
- Pull request: create it with the GitHub CLI after pushing; target the default branch.

1. Create and switch to branch (`BypassSandbox: true`):
   ```bash
   git checkout -b feat-<number>-<PascalCaseTitle>
   ```
2. Stage and commit (`BypassSandbox: true`, run sequentially so `.git/index.lock` does not race):
   ```bash
   git add README.md problems/<snake>/
   git commit -m "feat: solve <number>. <Title> with unit testing"
   ```
3. Push to remote (`BypassSandbox: true`):
   ```bash
   git push -u origin feat-<number>-<PascalCaseTitle>
   ```
4. Write the PR body to `<appDataDir>/brain/<conversation-id>/scratch/pr_body.md` using `write_to_file` (fill every `<...>` from the problem's `config.yml` and the real test counts; never leave placeholders):
   ```markdown
   ## Summary

   Adds LeetCode [<number>. <Title>](<leetcode_url>) (<Difficulty>, <tags>) with Python and C++
   solutions, each backed by unit tests.

   ## Solution

   - **Approach:** <one-line description of the user's algorithm, taken from their code/notes>
   - **Time:** <time complexity>
   - **Space:** <space complexity>

   ## Files added (`problems/<snake>/`)

   | File | Purpose |
   | --- | --- |
   | `BUILD.bazel` | Bazel target via `leetcode_problem()` |
   | `config.yml` | Problem metadata (number, title, URL, difficulty, tags, complexity) |
   | `<snake>.py` | Python solution (`<function_name>`) |
   | `<snake>_test.py` | pytest parametrized tests (<N> cases) |
   | `<snake>.h` | C++ function declaration |
   | `<snake>.cc` | C++ solution (`<function_name>`) |
   | `<snake>_test.cc` | GoogleTest parameterized tests (<N> cases) |

   ## Other changes

   - `README.md` regenerated: new problem row and updated badge counts.

   ## Testing

   - [x] `bazel test //problems/<snake>:test` passes (Python and C++)
   - [x] Python and C++ test cases are identical (same cases, order and count)
   - [x] `./scripts/format.sh` and `./scripts/lint.sh` are clean
   ```
5. Create the pull request (`BypassSandbox: true`, passing the scratch file path to `--body-file` for an auto-approvable command shape):
   ```bash
   gh pr create --title "Adds <number>. <Title> with unit testing" --body-file <appDataDir>/brain/<conversation-id>/scratch/pr_body.md
   ```
