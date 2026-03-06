# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken using the `clock()` function from the C standard library `<time.h>`. This function returns the amount of CPU time consumed by the program, expressed in clock ticks. To convert to seconds, each result was divided by `CLOCKS_PER_SEC`, which equals 1,000,000 on the Linux sandbox used for these experiments.

Three programs were measured: `baseline_loop.c`, `comparison_algorithms.c`, and `instrumentation_lab.c`. Each program was compiled with the following flags: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`. For `baseline_loop.c` and `comparison_algorithms.c`, the program was executed three consecutive times to observe timing variability. For `instrumentation_lab.c`, each internal phase was timed individually using separate `clock_t` variables placed immediately before and after each function call. The total time was measured by wrapping all three phases between a single `total_start` and `total_end` capture.

## Observed Performance Differences

The most significant performance difference was observed in `comparison_algorithms.c`, which compared two algorithms solving the same problem: counting even numbers in an array of 50,000 elements.

The naive algorithm, which uses two nested loops, recorded the following execution times across three runs: 2.793221 seconds, 2.784141 seconds, and 2.794941 seconds, for an average of 2.790768 seconds. The single-pass algorithm, which uses a single loop, recorded 0.000107 seconds, 0.000106 seconds, and 0.000107 seconds, for an average of 0.000107 seconds.

This means the naive algorithm is approximately 26,082 times slower than the single-pass algorithm, despite producing the same result.

In `baseline_loop.c`, a single loop over 100,000,000 iterations consistently ran in approximately 0.232 seconds across three runs, with a maximum variation of 0.004 seconds between runs. This confirms that timing variability on this sandbox is minimal for CPU-bound workloads.

In `instrumentation_lab.c`, the three internal phases produced the following times: BUILD_DATA took 0.000280 seconds, PROCESS took 0.000353 seconds, and REDUCE took 0.000135 seconds, for a TOTAL of 0.000773 seconds. The PROCESS phase was the most expensive, consuming approximately 46% of the total execution time.

## Relation Between Runtime and Energy Consumption

CPU time is directly related to energy consumption. A processor that runs a computation for 2.790768 seconds consumes significantly more energy than one that completes the same task in 0.000107 seconds. While this experiment did not measure energy in joules or watts directly, the execution time serves as a reliable proxy for energy usage when the CPU frequency and workload type remain constant.

Applied at scale, an algorithm that runs 26,082 times slower would consume proportionally more electricity for the same number of operations. Choosing the single-pass algorithm over the naive one is therefore not only a performance decision but also an energy efficiency decision.

## Limitations of the Experiment

The main limitation is that `clock()` measures CPU time, not wall-clock time. On a system running multiple processes, the actual elapsed time can differ from the CPU time reported. Additionally, no power measurement tool such as `perf stat` or hardware energy counters were used, so the link between runtime and energy consumption remains an estimate rather than a direct measurement.

The dataset size of 50,000 elements is fixed and relatively small. Results may differ significantly on larger datasets or on hardware with different cache sizes. Furthermore, each program was executed on a shared sandbox environment, which may introduce variability due to other running processes, even though no significant variation was observed across the three runs.

## Practical Engineering Takeaway

The measurements confirm that algorithm complexity has a far greater impact on performance and energy use than hardware speed. The naive algorithm runs in O(n²) time, performing approximately 1.25 billion operations for a dataset of 50,000 elements. The single-pass algorithm runs in O(n) time, performing only 50,000 operations. No hardware upgrade could close a gap of 26,082 times.

From a green engineering perspective, writing efficient algorithms is one of the most effective ways to reduce energy consumption in software. Before optimizing infrastructure or upgrading hardware, developers should first verify that their algorithms are not performing unnecessary work. The data collected in this experiment provides concrete evidence that this choice matters at every scale.
