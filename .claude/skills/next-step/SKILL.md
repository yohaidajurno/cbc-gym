---
name: next-step
description: Start-of-session routine. Reads the plan, checks git, reports where we are, and proposes the next ticket, then waits for approval. Use when Yohai runs /next-step.
disable-model-invocation: true
---

# /next-step

Follow the rules in `CLAUDE.md`, especially: short replies, and wait for OK.

## Steps

1. Read `CLAUDE.md` and `docs/roadmap.md`.
2. Find the current phase: the one marked 🟡, or else the first one marked ⬜. Read its file in `docs/phases/`, including the latest session note. If it has no file yet, go to **Planning a new phase**.
3. Check git:
   - `git status`: any uncommitted work, and which branch we're on. We work on `dev`.
   - `git fetch`, then compare `dev` with `origin/dev` (unpushed commits) and with `origin/main` (commits `dev` is missing).
   - `gh pr list`: any open pull requests.
4. Report in at most 3 short lines:
   - the current phase
   - what was done last
   - the git state: branch, uncommitted changes, unpushed commits, open pull requests
5. If something in git needs fixing first (wrong branch, `dev` behind `main`, a pull request waiting to be merged), propose that as the next step instead of a ticket.
6. Otherwise, propose the first unchecked ticket, with one short line for each:
   - **What:** what we will do
   - **Why:** the reason
   - **Files:** what will be created or changed
   - **Who writes it:** Yohai or Claude. Code is Yohai's by default; Yohai decides
   - **How we check:** how we know it works
   - **What you can show:** the picture, number or demo it produces, or "nothing yet"
7. Ask "OK?" and stop. Do nothing until Yohai approves.

## If every ticket in the phase is ticked

Propose marking the phase ✅ in its file and in `docs/roadmap.md`, and a pull request from `dev` to `main`. Then plan the next phase.

## Planning a new phase

1. Create `docs/phases/phase-N-<short-name>.md` with the same sections as `phase-0-setup.md`: status line, Goal, Done when, Checklist, Session notes.
2. Take the goal from the roadmap row. "Done when" must include the visual from the roadmap's "What you can show" column.
3. Propose the checklist one group of tickets at a time (A, B, C…), with each ticket small enough for one session. Wait for OK after each group.
4. Number tickets `N.1`, `N.2`, … straight through all groups.
5. Once the whole plan is approved, mark the phase 🟡 in its file and in `docs/roadmap.md`.
