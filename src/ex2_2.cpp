#include <iostream>
#include <omp.h>

static long num_steps = 100000000;
double step;
#define NUM_THREADS 2

int main() {
    int i, nthreads;
    double pi, sum[NUM_THREADS];

    step = 1.0 / (double) num_steps;
    omp_set_num_threads(NUM_THREADS);  // set the number of threads to be used in the parallel region

    double tdata = omp_get_wtime();  // returns the time in seconds since some point in the past.

    #pragma omp parallel  // This full block is run by all the threads
    {
        int i, id, nthrds;  // These are private variables with in the parallel block. Each thread will has same variables of their own
        double x;
        id = omp_get_thread_num();  // return the thread unique id
        nthrds = omp_get_num_threads();  // returns the total number of threads used in the parallel region
        if (id == 0) nthreads = nthrds;  // Execute this only for the thread 0
        for (i = id, sum[id]=0.0; i < num_steps; i = i + nthrds) {  // here, the i = i + nthrds is the tirck. for id=0(thread 0), the next i is 2 but for id 1(thread 1), the next i is 3.  So, each step is runned once.
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }  // This gives sum[0] and sum[1]

    for (i = 0, pi = 0.0; i < nthreads; i++)  // here we combine each thread output to get the final result
    {
        pi += sum[i] * step;
    }

    tdata = omp_get_wtime() - tdata;  // difference between the time after and before the parallel region gives the time taken by the parallel region
    std::cout << "Pi = " << pi << " with " << nthreads << " threads " << "in " << tdata << "secs\n";

    return 0;
}