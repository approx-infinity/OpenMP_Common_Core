#include <iostream>
#include <omp.h>

void work();

int tmp;
void danger() {
    tmp = 0;
    #pragma omp parallel private(tmp)
        work();
    std::cout << "Value = " << tmp << std::endl;
}

int main() {
    danger();

    return 0;
}

void work() {
    tmp =5;
}