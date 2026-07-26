#include <iostream>
#include <omp.h>

int main() {
    int tmp = 0;

    #pragma omp parallel for private(tmp)
    for (int j = 0; j < 1000; ++j) {
        tmp += j;
    }
    std::cout << "Value = " << tmp << std::endl;

    return 0;
}