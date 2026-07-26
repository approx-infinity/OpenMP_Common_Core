#include <iostream>
#include <omp.h>

int main() {
    int i, j = 5;
    double x = 1.0;
    double y = 42.0;
    
    // when we use default(none) then we must need to specify the variable storage attributes
    #pragma omp parallel for default(none) reduction(*:x) firstprivate(j) shared(y)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++)
            x += i * j + y;
    }
    std::cout << "x is " << x << std::endl;

    return 0;
}