#include <iostream>
#include <omp.h>

int main() {
    std::cout << "I think";

    #pragma omp parallel
    {
        #pragma omp single
        {
            // race condition
            #pragma omp task
              std::cout << " car";
            #pragma omp task
              std::cout << " race";
        }
    }
    std::cout << "s";
    std::cout << " are fun!\n";

    return 0;
}