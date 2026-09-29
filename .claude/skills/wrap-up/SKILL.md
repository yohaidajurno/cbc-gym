---
name: wrap-up
description: End-of-session routine. Ticks finished tickets, writes a session note, then proposes a commit, a push and, when a phase or group is done, a pull request to main. Use when Yohai runs /wrap-up.
disable-model-invocation: true
---

# /wrap-up

Follow the rules in `CLAUDE.md`, especially: short replies, and wait for OK.

## Steps

1. Work out which tickets were finished this session, from the conversation, `git status` and `git log`. A ticket counts as done only when its "How we check" passed.
2. Show Yohai, briefly:
   - the tickets to tick in the current phase file
   - a one-line session note: `- YYYY-MM-DD: <what was done>. Next: <next ticket>.`
   - any picture or demo made this session that is worth keeping. Propose saving it in `docs/media/` and linking it from the phase file.
3. Ask "OK?" and wait. Once approved, update the phase file: tick the tickets, and add the note at the top of "Session notes", newest first. Update `docs/roadmap.md` too if a phase status changed.
4. Check that we're on `dev`. Show the files that changed and propose one commit message in Conventional Commits style (`feat:`, `fix:`, `docs:`, `test:`, `ci:`, `chore:`).
5. Ask "Commit?" and wait. Commit only after OK.
6. Ask "Push?" and wait. After OK, push `dev` and report whether CI passed.
7. If a phase or a group of tickets is finished, propose a pull request from `dev` to `main`, with a title and a short description. Open it only after OK. Yohai reviews it and merges it on GitHub with **Create a merge commit**. After the merge, fast-forward `dev` to `main` and push it.
