// Every thread reads and writes the same variable.

#include <iostream>
#include <omp.h>

int main() {
    int x = 5;

    omp_set_num_threads(4);

    #pragma omp parallel shared(x)  // all threads share the same x
    {
        #pragma omp critical
        x++;
    }
    std::cout << x << std::endl;

    double A[1000];

    #pragma omp parallel for shared(A)
        for (int i = 0; i < 1000; i++){
            A[i] += 2;
        }
    std::cout << "A[0] = " << A[0] << std::endl;

    return 0;
}