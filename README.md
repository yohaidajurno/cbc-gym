# cbc-gym

A simulation gym for coherent beam combining (CBC): a model of a fiber-laser array and its far field, and a place to build, test and compare the controllers that phase-lock it.

## Status

Early development, Phase 0 (setup). See the [roadmap](docs/roadmap.md).

## Planned

- Simulate an array of fiber lasers and its far-field pattern
- Lock the array with classic controllers: hill-climbing, SPGD and LOCSET
- Benchmark them against noise, detector bit depth and channel count
- A live far-field viewer and Python bindings

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

## License

MIT. See [LICENSE](LICENSE).
