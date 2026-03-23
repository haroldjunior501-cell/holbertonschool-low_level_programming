# AI Memory Visualizer & Valgrind Tracer

## Project structure

```
ai_memory_visualizer_valgrind_tracer/
├── Makefile
├── programs/
│   ├── recursive_sum.c   — recursion + heap allocation
│   ├── pointer_alias.c   — stack array + heap copy + aliasing
│   ├── memory_errors.c   — intentional use-after-free, uninit read, leak
│   └── crash_me.c        — intentional segfault (two bugs)
└── analysis/
    ├── memory_maps.md    — Task 1: step-by-step memory maps
    ├── valgrind_analysis.md — Task 2: Valgrind output interpretation
    └── crash_report.md   — Task 3: crash root cause analysis
```

## Build

```bash
make all          # compile all programs
make clean        # remove binaries
```

## Quick reviewer guide

| File | What it demonstrates |
|---|---|
| `memory_maps.md` | Stack vs heap distinction, variable lifetimes, pointer aliasing, recursive frames |
| `valgrind_analysis.md` | Classification of use-after-free, uninit read, memory leak; AI critique |
| `crash_report.md` | Causal chain from code to SIGSEGV; two bugs identified; AI critique |

## Self-check results

- [x] Memory lifetimes explicitly explained in all three files
- [x] Pointer aliasing documented (`src` aliases `original[]` in `pointer_alias.c`)
- [x] Dangling pointers identified (after `free` in `recursive_sum.c` and `memory_errors.c`)
- [x] Valgrind findings interpreted with root cause, not just pasted
- [x] Crashes explained causally (loop bound + off-by-one → garbage pointer → strlen → SIGSEGV)
- [x] AI usage documented with at least 2 corrections per analysis file
- [x] AI treated as hypothesis, not authority
