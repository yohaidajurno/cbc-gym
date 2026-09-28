---
name: next-step
description: Start-of-session routine. Reads the plan, reports where we are, and proposes the next ticket, then waits for approval. Use when Yohai runs /next-step.
disable-model-invocation: true
---

# /next-step

Follow the rules in `CLAUDE.md`, especially: short replies, and wait for OK.

## Steps

1. Read `CLAUDE.md` and `docs/roadmap.md`.
2. Find the current phase (🟡) and read its file in `docs/phases/`, including the latest session note.
3. Run `git status` to see any uncommitted work.
4. Report in at most 3 short lines:
   - the current phase
   - what was done last
   - any uncommitted changes
5. Propose the first unchecked ticket in this format, with one short line each:
   - **What:** what we will do
   - **Why:** the reason
   - **Files:** what will be created or changed
   - **Who writes it:** Yohai or Claude (suggest one; Yohai decides)
   - **How we check:** how we know it works
6. Ask "OK?" and stop. Do nothing until Yohai approves.

## If every ticket in the phase is ticked

Propose marking the phase ✅ in `docs/roadmap.md` and starting the next phase. Plan the new phase file one group of tickets at a time, and wait for OK after each group.
