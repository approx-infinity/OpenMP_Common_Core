// Without padding:
//
// Cache Line 0
// +---------------------------------------------------------------+
// | sum[0] | sum[1] |                     unused                  |
// +---------------------------------------------------------------+
//   Thread0   Thread1
//
// Both threads modify the same cache line
// → False sharing

// With padding:
//
// Cache Line 0
// +---------------------------------------------------------------+
// | sum[0][0] | padding | padding | padding | ...                |
// +---------------------------------------------------------------+
//
// Cache Line 1
// +---------------------------------------------------------------+
// | sum[1][0] | padding | padding | padding | ...                |
// +---------------------------------------------------------------+
//
// Each thread writes to a different cache line
// → No false sharing

#include <iostream>
#include <omp.h>

static long num_steps = 100000000;
double step;
#define PAD 8  // assume 64 byte L1 cache line size
#define NUM_THREADS 2

int main() {
    int i, nthreads;
    double pi, sum[NUM_THREADS][PAD];

    step = 1.0 / (double) num_steps;
    omp_set_num_threads(NUM_THREADS);

    double timed = omp_get_wtime();

    #pragma omp parallel
    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        if (id == 0) {
            nthreads = nthrds;
        }

        for (i = id, sum[id][0] = 0.0; i < num_steps; i += nthrds) {
            x = (i + 0.5) * step;
            sum[id][0] += 4.0 / (1.0 + x * x);
        }
    }
    for (i = 0, pi = 0.0; i < nthreads; i++) {
        pi += sum[i][0] * step;
    }
    
    timed = omp_get_wtime() - timed;
    std::cout << "Pi = " << pi << " in " << timed << " secs\n";

    return 0;
}