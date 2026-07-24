# OpenMP_Common_Core

In this repository, we are learning OpenMP and its common core concepts. The goal is to understand how to effectively use OpenMP for parallel programming in C++.

We will cover only 19 items of the OpenMP common core. They are:
1. #pragma omp parallel
2. int omp_get_num_threads()
3. int omp_get_thread_num()
4. double omp_get_wtime()
5. setenv OMP_NUM_THREADS N
6. #pragma omp barrier
7. #pragma omp critical
8. #pragma omp for
9. #pragma omp parallel for
10. reduction(op:list)
11. schedule(dynamic[, chunk])
12. schedule(static[, chunk])
13. private(list)
14. firstprivate(list)
15. shared(list)
16. nowait
17. #pragma omp single
18. #pragma omp task
19. #pragma omp taskwait

## 1. #pragma omp parallel
The `#pragma omp parallel` directive is used to create a parallel region in the code. it allows multiple threads to execute the code block concurrently. Each thread will execute the code within the parallel region independently. Each thread will have its own copy of variables in the parallel region unless specified otherwise.

In [example 1](src/ex1_1.cpp), we demonstrate the use of `#pragma omp parallel` to create a parallel region where multiple threads print "hello world" with the default number of threads available on the system. The output will show that multiple threads are executing the code concurrently. The output order of the printed messages may vary each time the program is run, as the threads are scheduled by the operating system.

## 2. int omp_get_num_threads()
The `omp_get_num_threads()` function returns the number of threads currently in the parallel region. See [example 2](src/ex2_2.cpp) for a demonstration of how to use this function to get the number of threads in a parallel region.

## 3. int omp_get_thread_num()
The `omp_get_thread_num()` function returns the thread number of the calling thread within the current parallel region. The thread number is a unique identifier for each thread, starting from 0 up to the total number of threads minus one. See [example 2](src/ex2_2.cpp) for a demonstration of how to use this function to get the thread number of each thread in a parallel region.

## 4. double omp_get_wtime()
The `omp_get_wtime()` function returns the elapsed wall clock time in seconds since some point in the past. It is used to measure the execution time of a code block. See [example 2](src/ex2_2.cpp) for a demonstration of how to use this function to measure the execution time of a parallel region.