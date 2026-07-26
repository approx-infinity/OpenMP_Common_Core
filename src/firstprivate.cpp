// firstprivate is like private, but each thread starts with the original value.
// int x = 5;
// Thread0 : x = 5 
// Thread1 : x = 5 
// Thread2 : x = 5 
// Thread3 : x = 5

#include <iostream>
#include <omp.h>

int main() {
    int x = 5;

    #pragma omp parallel firstprivate(x)
    {
        x++;
        
        #pragma omp critical
        std::cout << "Thread : " << omp_get_thread_num() << ", x = " << x << std::endl;
    }

    std::cout << "out of scope x = " << x << std::endl;

    return 0;
}