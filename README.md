# OpenMP_Common_Core

This repository is a small set of C++ OpenMP examples that cover the common core ideas: parallel regions, thread info, timing, barriers, critical sections, loops, reductions, scheduling, variable scope, tasks, and task synchronization.

## Reference Book

- [OpenMP Common Core](docs/omp-common-core.pdf)

## Files

Basics and thread info:
- [src/ex1.cpp](src/ex1.cpp)
- [src/ex1_1.cpp](src/ex1_1.cpp)
- [src/ex2.cpp](src/ex2.cpp)
- [src/ex2_1.cpp](src/ex2_1.cpp)
- [src/ex2_2.cpp](src/ex2_2.cpp)
- [src/ex3.cpp](src/ex3.cpp)
- [src/ex4.cpp](src/ex4.cpp)
- [src/ex5.cpp](src/ex5.cpp)

Variable scope:
- [src/default_none_.cpp](src/default_none_.cpp)
- [src/private.cpp](src/private.cpp)
- [src/private_clause.cpp](src/private_clause.cpp)
- [src/private_clause2.cpp](src/private_clause2.cpp)
- [src/firstprivate.cpp](src/firstprivate.cpp)
- [src/shared.cpp](src/shared.cpp)

Tasks and synchronization:
- [src/single_task.cpp](src/single_task.cpp)
- [src/pi_with_task.cpp](src/pi_with_task.cpp)

Parallel programs:
- [src/fibonacci.cpp](src/fibonacci.cpp)
- [src/fibonacci_parallel.cpp](src/fibonacci_parallel.cpp)
- [src/Mandelbrot.cpp](src/Mandelbrot.cpp)

The code is meant to be read, compiled, and compared example by example so the OpenMP behavior is easy to see.
