*This project has been created as part of the 42 curriculum by srouhi and shkhadka*
# Push_swap 🚀

An adaptive, high-performance sorting pipeline developed as a group project at **42 Berlin**. 

---

## 📝 Description
The goal of **Push_swap** is simple: sort a random stack of integers using two stacks (`a` and `b`) and a highly limited set of operations (such as `sa`, `pb`, `ra`, `rrb`) while using the **absolute minimum number of moves**.

This program evaluates the size of the input elements and dynamically selects the most optimal algorithmic strategy:
* **Small Sizes (<= 5 elements):** Uses specialized micro-sorting logic.
* **Large Sizes (100 to 500+ elements):** Implements a customized **Chunk Sort** (sliding-window tier sort) utilizing a pre-sorted static array index mapping to bypass dynamic stack scaling constraints.

---

## 🛠️ Instructions

### 1. Compilation & Installation
The project compiles into the `push_swap` binary using a strict `Makefile`. Run the following command in your terminal:
```bash
make
```

To clean object files:
``` make clean```

To force full re-compilation: 
``` make re ```

2. Basic Execution
Pass a formatted list of integers as space-separated arguments:

```Bash
./push_swap 4 67 3 87 23
```

#### Quick-Test Suite
Use these pre-made terminal commands to test edge cases and performance quickly without getting bored.

## 1. Edge Cases (Must exit silently with 0 moves)
bash
```
# Test 1: Zero arguments passed
./push_swap

# Test 2: Only one single element
./push_swap 42

# Test 3: Already sorted numbers
./push_swap 1 2 3 4 5
```
##  2. Error Management (Must output 'Error' to stderr)

Bash
```
# Test 1: Empty string argument
./push_swap "" 1 2 3

# Test 2: Non-numeric parameters
./push_swap 1 2 three 4

# Test 3: Duplicate detection
./push_swap 1 2 3 2

# Test 4: Integer Overflow / Underflow boundaries
./push_swap 2147483648 1 2
./push_swap -2147483649 1 2
```

## 3. Adaptive Sorting Strategies

The program implements an **Adaptive Sorting Architecture** that dynamically evaluates the size and complexity of the stack to choose the most efficient mechanical sorting strategy:

### 1. Simple Sort (Micro Datasets)
* **Target:** Small inputs ($\le$ 5 values) handled by `small_sort.c`.
* **Logic:** Hardcoded optimal decision trees. For 3 values, it solves the stack in a maximum of 3 moves; for 5 values, it keeps the footprint under 12 moves by isolating the smallest elements.
* **Test Command:**
  ```bash
  ARG="4 67 3"; ./push_swap $ARG | ./checker_linux $ARG
  ```

### 2. Medium/Complex Sort (Chunk-Based Mechanical Sort)
Target: Medium to large datasets (100 to 500+ values) handled by chunk_sort.c, big_sort.c, and cost_calculator.c.

Logic: Dividers push numbers in dynamically sized "chunks" into Stack B. Once split, it uses a calculated mechanical index to find the "cheapest" node to push back, factoring in the cost of rotating both stacks simultaneously (rr, rrr).
Test Command (100 values):
```
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```
### 3. Adaptive Intelligence Fallback
Target: Specific pre-sorted, inverted, or high-disorder configurations analyzed by adaptive.c.

Logic: Calculates mathematical inversions and disorder density. If the dataset benefits from multi-bit partitioning, it activates alternative paths (like our radix_sort.c framework) to minimize mechanical overhead and bypass chunking bottlenecks.
Test Command (500 values):
```
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```
## 4. Performance Benchmarks & Checker Verification
Bash

`Benchmark 100 Elements (Target: < 700 moves)`

```
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```
`Benchmark 500 Elements (Target: Good Performance < 7000 moves)`

```
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```
## 5. Benchmark Mode Verification
Beyond raw move counting, the binary embeds a built-in benchmark mode. Passing the --bench flag prints, to stderr only, the measured disorder of the input (before any move is made), the strategy that was selected along with its theoretical complexity class, the total operation count, and a breakdown of every operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr). Stdout is untouched, so --bench can always be combined with the checker in the same pipeline.
--bench works with every strategy flag, and the flag order does not matter:
```bash
# Bench report with the default adaptive strategy
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap --bench $ARG 1>/dev/null

# Bench report while a specific strategy is forced
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap --bench --simple $ARG 1>/dev/null
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap --bench --medium $ARG 1>/dev/null
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap --bench --complex $ARG 1>/dev/null

# Flag order does not matter
./push_swap --medium --bench 5 4 3 2 1 9 8 1>/dev/null
```
Confirm that stdout (the operation stream) and stderr (the bench report) stay fully separated, and that the operations printed on stdout still sort correctly with the checker even while --bench is active:
```bash
# Save the bench report to a file while piping the sorted moves to the checker
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap --bench --adaptive $ARG 2>bench.log | ./checker_linux $ARG
cat bench.log

# Confirm the reported total matches the actual number of printed moves
ARG=$(seq 1 200 | shuf | tr '\n' ' '); ./push_swap --bench --adaptive $ARG 2>/tmp/bench.log 1>/tmp/ops.txt
grep "Total operations" /tmp/bench.log
wc -l /tmp/ops.txt
```
Edge case: an already-sorted stack still produces a valid bench report (0.00% disorder, 0 total operations) instead of silently skipping it:
```bash
./push_swap --bench 1 2 3 4 5
```


## 6. Testing & Memory Verification

To ensure the sorting efficiency and guarantee zero memory leaks (as required by the 42 school standard), we utilized rigorous testing methodology and memory profiling tools.

### 1. Visualizer & Correctness Test
To verify if the numbers are properly sorted and to trace the mechanical moves execution:
```bash
# Run push_swap with a random set of numbers and check with the checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG 

# Count the number of instructions executed
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

```
#### Memory Leak Testing (Valgrind)
We systematically verified every component (from parsing arguments to stack destruction) to ensure there are no memory leaks or invalid read/write operations.
```
# General leak check with custom arguments
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 4 67 3 87 23

# Error handling memory test (checks if memory is freed correctly upon exit)
valgrind --leak-check=full ./push_swap "1 2 3 2"
valgrind --leak-check=full ./push_swap "abc" ""
```
## Custom Algorithm Control Flags

To facilitate benchmarking, explicit debugging, and granular performance analysis, our `push_swap` implementation supports custom runtime flags. These allow you to bypass the automatic adaptive selection and force a specific sorting framework:

### 1. Force Micro/Simple Sort (`--simple`)
Forces the engine to use the specialized decision tree designed for tiny datasets, regardless of the stack size.
```bash
# Manually invoke the small_sort logic
./push_swap --simple 3 1 2
```
## 2. Force Chunk/Cost Sort (`--medium`)
Bypasses both the micro-sort and the radix fallback, pushing elements into partitioned blocks and executing strict proximity cost-calculations.
```bash
# Force the chunking and cost-calculation engine on 100 values
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap --medium $ARG | wc -l
```
## 3. Force Complex / Alternative Logic (`--complex`)
Directly invokes our multi-bit or alternative complex sort pathway (e.g., Radix or advanced sub-chunking), optimized for massive data distribution.
```bash
# Force the complex binary/bit-partitioning logic
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap --complex $ARG | wc -l
```
## 4. Default Adaptive Mode (`--adaptive`)
Runs the full evaluation suite. It samples data entropy, counts inversion pairs, and automatically chooses the most optimized execution path (this is the default behavior if no flag is provided).
```bash
# Explicitly or implicitly run the intelligent adaptive sort
./push_swap --adaptive 4 67 3 87 23
```

## 👥 Group Division of Work
Both team members understand and can fully defend every segment of this codebase:

* **Sanaz Rouhi (@sunshinebraid / srouhi):**
	* Designed the primary low-level memory handling routines for stack structure manipulation (`stack.c`).
	* Developed and implemented the project's orchestration foundation (`main.c`, `strategy.c`).
	* Programmed the input validation parsing logic (`parser.c`) and custom text utility wrappers (`parse_utils.c`).
	* Created the core string tokenization architecture (`ft_split.c`).
	* Designed and optimized micro-sorting logic for small datasets (`small_sort.c`).
	* Implemented structural helper tools for dynamic list manipulation (`stack_utils.c`).
	* Drafted the sliding-window multi-chunk sort division setup (`chunk_sort.c`).
 

* **@shkhadka (shkhadka):**
	* Programmed all low-level hardware operation rules (`operations_push.c`, `operations_swap.c`, `operations_rotate.c`, and `operations_reverse_rotate.c`).
	* Authored the initial execution framework for optimized push/rotate movements (`big_sort.c`, `execute_cheapest.c`).
	* Implemented the multi-bit Radix fallback sorting algorithm (`radix_sort.c`).
	* Conceptualized and implemented the mathematical inversion mapping and disorder evaluation structure (`adaptive.c`).
	* Optimized and finalized the cost and positioning mechanics for mechanical move tracking (`cost_calculator.c`).
	

##### Resources & AI Usage

## 📚 Resources & Credits

Our development process strictly reflects the core philosophy of collaborative engineering, utilizing diverse learning channels to build, optimize, and debug this project:

* **Peer-to-Peer Learning:** Leveraged the collective intelligence of fellow 42 students to design the argument parsing logic and map out the initial mechanical visualization of the stacks.
* **Algorithm & Conceptual Research:** Explored advanced sorting mechanics, cost-calculation strategies, and sorting logic through educational YouTube tutorials and technical documentation on Google.
* **Debugging, Refactoring & Testing:** Maintained code quality, accelerated optimization bottlenecks, and verified complex error-handling edge cases through interactive AI collaboration.
