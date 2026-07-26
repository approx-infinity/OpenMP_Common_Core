// A private variable means every thread gets its own copy.
// but the variable is unspecified
// we can get any arbitary value

#include <iostream>
#include <omp.h>

int main() {
    int x = 5;

    #pragma omp parallel private(x)
    {
        #pragma omp critical
        {
            std::cout << "Thread : " << omp_get_thread_num() << ", x = " << x << std::endl;
        }
    }
    
    std::cout << "\n\n\n";

    #pragma omp parallel private(x)
    {
        x++;
        #pragma omp critical
        std::cout << "Thread : " << omp_get_thread_num() << ", x = " << x << std::endl;
    }

    std::cout << "out of scope x = " << x << std::endl;

    return 0;
}