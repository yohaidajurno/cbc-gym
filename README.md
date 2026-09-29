# cbc-gym

A beam-shape designer for fiber-laser arrays, written in C++.

Many fiber lasers can work as one powerful laser when their light waves stay in step. This is called coherent beam combining (CBC). The phase of each fiber decides where the light adds up, so the combined beam can form a dot, a ring, a line or several spots.

cbc-gym computes those phases. You give it a target shape, and it finds the phases that put as much light as possible on that shape, within real limits: 36 to 400 fibers, gaps between them, and 8-bit phase control.

## Why

- **No formula.** Phases → shape is one calculation, but shape → phases has to be searched for.
- **Wasted light.** The gaps between fibers create unwanted side lobes, which take power away from the shape.
- **A gap in open source.** Holography has strong methods for this search, but they're built for display chips with millions of pixels. Fiber arrays have a few hundred elements with gaps between them, and I found no public project that designs shapes for them.

## Planned

- **Plant model:** simulate the fiber array and its far field from the specs of real components
- **Scoring:** the same four numbers for every method: power on target, side lobes, shape accuracy and speed
- **Designers:** classic optimizers (Gerchberg–Saxton, gradient descent), an improved optimizer, and fast sequences of patterns whose average forms the shape
- **AI designer:** a small network, trained on optimizer results, that computes phases in microseconds
- **Robustness:** keep the shape under phase noise, and redesign around a dead fiber
- **Live app:** a C++ window (Dear ImGui) to change the phases and watch the far field; later, draw a target shape and run any designer, in the browser too

## Status

Phase 0 (setup) is done. Next: Phase 1, the plant model. See the [roadmap](docs/roadmap.md).

## Build

Requires CMake 3.25 or newer, Ninja, and a C++20 compiler.
Run these commands from the project folder:

```sh
cmake --workflow --preset debug # Configure, build and test in one command
```

Replace `debug` with `release` or `memory-check` for another configuration.
To perform the steps individually and run the demo:

```sh
cmake --preset debug          # Configure: generate build instructions
cmake --build --preset debug  # Build: compile and link the program
./build/debug/cbc_hello       # Run the demo
```

After editing C++ source files, repeat the build and run commands.

`CMakePresets.json` stores three named configurations, each in its own folder:

| Preset | Purpose | Build folder |
| --- | --- | --- |
| `debug` | Debug symbols for investigating problems | `build/debug` |
| `release` | Compiler optimizations for speed | `build/release` |
| `memory-check` | Debug build with AddressSanitizer and UndefinedBehaviorSanitizer | `build/memory-check` |

To use another preset, replace `debug` in all three commands with its name.
The memory-check preset requires Clang or GCC. Its checks run when you execute
the program; they can only detect problems in code that actually runs.

The first configuration of each build folder downloads GoogleTest and verifies
its SHA-256 checksum; internet access is required. Project targets enable strict
compiler warnings and treat them as errors. Downloaded dependencies do not
inherit that warning policy. After building, run the automated tests with:

```sh
ctest --preset debug
```

Use the `release` or `memory-check` test preset for those configurations instead,
after configuring and building the corresponding preset. An empty test suite
is an error, and individual tests have a 30-second timeout.

## Continuous integration

`.github/workflows/ci.yml` defines the GitHub Actions checks for pushes and pull
requests. Three jobs build and test the debug, release and memory-check presets
on Ubuntu 24.04 with GCC 13. Another job builds and tests debug on macOS 15 with
AppleClang. These jobs use the same `cmake --workflow --preset` command as local
development. A separate quality job uses Clang 18 to check formatting and run
static analysis. Each job has a five-minute limit.

Formatting differences and clang-tidy findings in project code fail the quality
job. CI checks formatting without changing files. Use clang-format 18 locally
for consistent results with CI; other versions can format some code differently.
The runner and package patch versions can change as Ubuntu receives updates.

The workflow uses read-only repository permissions and a checkout action pinned
to a commit. All five checks must pass, and the branch must be up to date with
`main`, before a pull request can merge. These rules also apply to administrators.

## Workflow

- Work happens on the `dev` branch.
- `main` changes only through a pull request from `dev`, after all checks pass.
- Those pull requests use **Create a merge commit**, not squash, so `dev` and `main` keep the same history. After a merge, `dev` is fast-forwarded to `main`.
- The plan lives in [docs/roadmap.md](docs/roadmap.md), and the current phase has its own checklist in [docs/phases/](docs/phases/).
- Commit messages follow [Conventional Commits](https://www.conventionalcommits.org/) (`feat:`, `fix:`, `docs:`, `test:`, `ci:`, `chore:`).

## License

MIT. See [LICENSE](LICENSE).
