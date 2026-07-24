#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        std::cout << "hello ";
        std::cout << "world \n";
    }
    return 0;
}