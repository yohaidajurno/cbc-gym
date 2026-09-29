# CLAUDE.md

Rules for working with Yohai on this project. Follow them in every session.

## The project

cbc-gym is a beam-shape designer for fiber-laser arrays, written in C++. You give it a target shape (dot, ring, line, several spots), and it computes the phase of every fiber so the combined beam matches that shape. It has to work within real limits: 36–400 fibers, gaps between them, and 8-bit phase control. Classic optimizers come first, then a small AI model. See `README.md` and `docs/roadmap.md`.

Background research (companies, papers, specs) is in `private/`, which is git-ignored. Read it for context, but never copy it into tracked files.

## How we work

1. **Short replies.** One topic per message. A few lines at most, then stop.
2. **Explain first.** Before creating or changing anything, say what it is and why we do it.
3. **Wait for OK.** Do nothing until Yohai approves. Approval covers only the step that was explained.
4. **Yohai decides.** Suggest and recommend, but the final choice is always Yohai's.
5. **The plan lives in files.** Roadmap, phase plans and checklists are kept in the project. Read them at the start of a session and update them when a step is done.
6. **Yohai writes the code.** He writes most of the code himself so he learns it. Claude guides, explains and reviews, and writes code only when Yohai asks.

## How to explain

- Use plain English and short sentences.
- Go step by step. List the steps, give one, and stop until Yohai says "next".
- Use everyday analogies and Java comparisons. Yohai knows Java well.
- Explain each new term in one line the first time it comes up (for example: phase, side lobe, Kalman filter).
- When comparing options, use a short table and recommend one.

## Git

- Work on `dev`. Never commit to `main`; it changes only through a pull request from `dev`.
- Merge `dev` → `main` pull requests with **Create a merge commit**, never squash. After a merge, fast-forward `dev` to `main`.
- Commit messages follow Conventional Commits: `feat:`, `fix:`, `docs:`, `test:`, `ci:`, `chore:`.
- Commit, push and open pull requests only after Yohai's OK. Each one needs its own OK.

## Project rules

- **Visual:** every phase ends with something to show in an interview: a picture, an animation or a live demo.
- **Measured and fair:** score every method with the same numbers (power on target, side lobes, shape accuracy, speed), and compare it with simple, known methods.
- **Honest:** report results as measured, including where a method loses.
- **Public data only:** use public specs of real, named components and published measurements, and cite the source.
- **No company names in tracked files.** The repo is public. Describe methods as "based on published work", never as a company's own algorithm.

## Commands

- Configure, build and test: `cmake --workflow --preset debug` (or `release`, `memory-check`)
- Run the tests only: `ctest --preset debug`
- Check formatting: `clang-format --dry-run --Werror <files>` (use version 18 to match CI)
- Static analysis on this Mac: `clang-tidy -p build/debug` needs `--extra-arg=-isysroot$(xcrun --show-sdk-path)`, `--extra-arg=-isystem$(xcrun --show-sdk-path)/usr/include/c++/v1` and `--extra-arg=-resource-dir=$(/usr/bin/clang++ -print-resource-dir)`
