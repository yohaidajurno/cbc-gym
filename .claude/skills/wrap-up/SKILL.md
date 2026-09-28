---
name: wrap-up
description: End-of-session routine. Ticks finished tickets, writes a session note, and proposes a commit. Use when Yohai runs /wrap-up.
disable-model-invocation: true
---

# /wrap-up

Follow the rules in `CLAUDE.md`, especially: short replies, and wait for OK.

## Steps

1. Work out which tickets were finished this session, from the conversation and `git status`.
2. Show Yohai, briefly:
   - the tickets to tick in the current phase file
   - a one-line session note: `- YYYY-MM-DD: <what was done>. Next: <next ticket>.`
3. Ask "OK?" and wait. Once approved, update the phase file (and `docs/roadmap.md` if a phase status changed).
4. Show the files that changed and propose one commit message in Conventional Commits style (`feat:`, `fix:`, `docs:`, `chore:`, `test:`, `ci:`).
5. Ask "Commit?" and wait. Commit only after OK.
