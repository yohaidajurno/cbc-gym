# Phase 0 — Setup and workflow

Status: 🟡 in progress · Started: 2026-09-28

## Goal

A professional project base: git, GitHub, one-command build, tests, automatic quality checks and a workflow that carries across sessions.

## Done when

- A fresh clone builds and passes its tests with one command.
- CI runs the tests on every pull request, and `main` is protected.
- The plan, rules and workflow skills are in the repo.

## Checklist

### A. Workspace

- [x] 0.1 Create the git repo and a git-ignored `private/` folder for the research
- [x] 0.2 Create this Phase 0 plan file
- [x] 0.3 Create the `/next-step` and `/wrap-up` skills
- [x] 0.4 Make the first commit
- [x] 0.5 Rename the folder to `cbc-gym`

### B. GitHub

- [x] 0.6 Add a README and a LICENSE
- [x] 0.7 Create a GitHub repo and push (currently public)
- [x] 0.8 Protect `main` (changes only through pull requests)

### C. Build and tests

- [x] 0.9 Smallest CMake project that compiles
- [x] 0.10 Build presets: debug, release, memory check
- [x] 0.11 GoogleTest with one passing test

### D. Quality

- [x] 0.12 Auto-formatter (`clang-format`)
- [x] 0.13 Static checker (`clang-tidy`)
- [x] 0.14 CI on GitHub for every change
- [ ] 0.15 One real pull request through the whole flow

## Session notes

- 2026-09-29: Opened PR #1 from `setup/cmake`. All five GitHub CI jobs passed (Linux debug/release/memory-check, macOS debug, code quality), and a fresh remote clone passed the one-command debug workflow. Enabled all five required checks and up-to-date branches on `main`, preserving existing protections and administrator enforcement. Confirmed GitHub reports the repository as public. Next: review and merge PR #1 to finish 0.15.
- 2026-09-29: Added one-command CMake workflows for all three presets, project-only compiler warnings as errors, a SHA-256 check for GoogleTest, and a macOS debug CI job. All three local workflows passed, plus a debug workflow from a fresh source copy in a temporary directory; actionlint passed. First GitHub run, verification of required status checks, and the real PR remain pending.
- 2026-09-29: Implemented the CI workflow for 0.14: GCC 13 debug/release/memory-check builds and tests plus Clang 18 formatting/static analysis on Ubuntu 24.04, five-minute job limits, read-only permissions and pinned checkout. Remote execution is pending; leave 0.14 unchecked until GitHub runs it successfully.
- 2026-09-29: Completed 0.13. Yohai created `.clang-tidy` with analyzer, bugprone and performance checks. The bundled clang-tidy checked all three project `.cpp` files with no project diagnostics; dependency warnings were suppressed. On this Mac the invocation needed `--extra-arg=-isysroot$(xcrun --show-sdk-path)`, `--extra-arg=-isystem$(xcrun --show-sdk-path)/usr/include/c++/v1` and `--extra-arg=-resource-dir=$(/usr/bin/clang++ -print-resource-dir)` alongside `-p build/debug`. Next: 0.14 (GitHub CI).
- 2026-09-29: Completed 0.12. Yohai created `.clang-format` (Google style, two-space indentation, 100-column limit) and formatted through VS Code's clangd. All four C++ source/header files passed `clang-format --dry-run --Werror` using the formatter bundled with the C/C++ extension.
- 2026-09-29: Completed 0.11. Connected GoogleTest 1.18.0 through CMake FetchContent and registered Yohai's version test with CTest. Debug configuration built successfully; 1/1 tests passed. Next: 0.12 (clang-format). Yohai prefers slow explanations using Java comparisons and writing code himself unless he explicitly asks the assistant to edit.
- 2026-09-29: Completed 0.10. Added debug, release and memory-check presets and README instructions. All three configured, built and ran with AppleClang; each printed `cbc-gym 0.1.0`. Next: 0.11 (GoogleTest with one passing test).
- 2026-09-29: Verified 0.9 with `cmake -S . -B build`, `cmake --build build`, and `./build/cbc_hello`; demo printed `cbc-gym 0.1.0`. Next: 0.10 (build presets).
- 2026-09-28: Wrote CLAUDE.md and the roadmap, planned Phase 0, and finished 0.1–0.4. Next: 0.5. If the folder is already named `cbc-gym`, tick 0.5 and continue with 0.6.
