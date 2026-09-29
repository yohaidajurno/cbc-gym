# Roadmap

Each phase is an epic. Only the current phase is planned in detail, in `docs/phases/`.

Status: ⬜ not started · 🟡 in progress · ✅ done

## The idea

A beam-shape designer for fiber-laser arrays. You give it a target shape (dot, ring, line, several dots), and it computes the phase of every fiber so the combined beam matches that shape. It has to work within real limits: 36–400 fibers, gaps between them, and 8-bit phase control.

It starts with classic optimizers, then adds a small AI model that computes the phases instantly. It's based on methods from holography, adapted to fiber arrays. I found no public project that does this.

## Rules for every phase

- **Visual:** every phase ends with a picture, animation or live demo that can be shown in an interview.
- **Measured:** every method is scored with the same numbers (power on target, side lobes, shape accuracy, speed).
- **Fair:** every new method is compared with simple, known ones on the same shapes.
- **Real data:** the model uses public specs of real, named components and published measurements.

## Phases

| Phase | Name | Goal | What you can show | Status |
| --- | --- | --- | --- | --- |
| 0 | Setup and workflow | Repo, build, tests and CI ready; workflow in place | Green CI on every pull request | ✅ |
| 1 | Plant model and live app | Simulate the fiber array and its far field from real component specs; match published figures (≈ 60% main lobe, ≈ 6% side lobes for 6 × 6); show it in a live C++ app | Live app: change the phases, watch the far field change | ⬜ |
| 2 | Scoring and baselines | Target shapes, the four scores, and simple designers (Gerchberg–Saxton, gradient descent) | Gallery: target vs result for each shape, plus a score table | ⬜ |
| 3 | Shape editor and web version | Draw a target shape in the app and run any designer live; build the app for the browser | A link that opens the app in the browser | ⬜ |
| 4 | Better designer | Optimizer that respects 8-bit control, reduces side lobes and handles off-centre shapes | Before/after images, with numbers that beat the baselines | ⬜ |
| 5 | Shape sequences | Fast sequences of simple patterns whose average forms the target shape | Animation: the sequence building up the shape | ⬜ |
| 6 | AI designer | Small network trained on optimizer results; computes phases in microseconds | Side by side: AI vs optimizer, quality and speed | ⬜ |
| 7 | Real-world robustness | Keep the shape under phase noise (SPGD lock); detect a dead fiber and redesign around it | Animation: a fiber fails and the shape recovers | ⬜ |
| 8 | Release | README with gallery, demo video, technical note, v1.0 | 3-minute demo video | ⬜ |

## Ideas for later

Not planned yet. Revisit once the phases above are done.

- Air turbulence (wind, hot and cold air) as extra phase noise
- Predictive control: forecast phase drift between detector samples; AI compared with a Kalman filter
- Small local models per group of fibers that share a little information
- Camera-in-the-loop: learn the gap between the model and a real laser
- Hardware path: a controller on an FPGA, tested against the simulator
