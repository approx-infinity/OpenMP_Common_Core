#include <iostream>
#include <omp.h>

static long num_steps = 100000000;
double step;
#define NUM_THREADS 2

int main() {
    int nthreads;
    double pi = 0.0;

    step = 1.0 / (double) num_steps;
    omp_set_num_threads(NUM_THREADS);

    double timed = omp_get_wtime();
    
    #pragma omp parallel
    {
        int i, nthrds;
        double x, sum;  //local scalar sum variable

        int id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        if (id == 0) {
            nthreads = nthrds;
        }

        for (i = id, sum = 0.0; i < num_steps; i += nthrds) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);  // No array, so no false sharing
        }

        #pragma omp critical  // each thread runs this block one by one at a time
        {
            pi += sum * step;
        }
    }

    timed = omp_get_wtime() - timed;
    std::cout << "Pi = " << pi << " in " << timed << " secs\n";

    return 0;
}