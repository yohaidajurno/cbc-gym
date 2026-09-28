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
- [ ] 0.7 Create a private GitHub repo and push
- [ ] 0.8 Protect `main` (changes only through pull requests)

### C. Build and tests

- [ ] 0.9 Smallest CMake project that compiles
- [ ] 0.10 Build presets: debug, release, memory check
- [ ] 0.11 GoogleTest with one passing test

### D. Quality

- [ ] 0.12 Auto-formatter (`clang-format`)
- [ ] 0.13 Static checker (`clang-tidy`)
- [ ] 0.14 CI on GitHub for every change
- [ ] 0.15 One real pull request through the whole flow

## Session notes

- 2026-09-28: Wrote CLAUDE.md and the roadmap, planned Phase 0, and finished 0.1–0.4. Next: 0.5. If the folder is already named `cbc-gym`, tick 0.5 and continue with 0.6.
