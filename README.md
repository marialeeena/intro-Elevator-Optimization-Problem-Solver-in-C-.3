# Elevator Optimization Problem Solver in C

A comprehensive C project developed as part of an introductory programming assignment, implementing and comparing multiple algorithmic approaches to solve an elevator scheduling and optimization problem. 

The project strictly avoids floating-point arithmetic, auxiliary string/array libraries, or external math libraries, relying purely on standard I/O (`<stdio.h>`) and dynamic memory allocation (`<stdlib.h>`).

## Implemented Methods

1. **Pure Recursive Method (`liftrec.c`):** Implements the foundational mathematical recurrence relation.
2. **Brute Force Method (`liftbf.c`):** Systematically explores all potential elevator stop combinations to find the global optimum.
3. **Recursive with Memoization (`liftmem.c`):** Optimizes the top-down recursive approach using a 2D cache table to avoid redundant calculations.
4. **Dynamic Programming (`liftdp.c`):** Bottom-up iterative approach utilizing auxiliary state tracking to efficiently compute costs and reconstruct optimal stop sequences.

## Compilation & Execution

To compile and run any specific method, link `lift.c` with the desired module header and source file. For example, to run the Dynamic Programming version:


gcc -c lift.c
gcc -c liftdp.c
gcc -o liftdp lift.o liftdp.o
./liftdp


(You can replace liftdp with liftrec, liftbf, or liftmem depending on the method you want to test).
