#include <iostream>
#include <omp.h>

long long fib(int n) {
    long long x, y;

    if (n < 2) {
        return n;
    }

    #pragma omp task shared(x)
      x = fib(n-1);
    #pragma omp task shared(y)
      y = fib(n-2);
    #pragma omp taskwait
      return (x + y);
}

int main() {
    int NW = 50;
    long long res = 0;

    #pragma omp parallel
    {
        #pragma omp single
          res = fib(NW);
          std::cout << "Result = " << res << std::endl;
    }
    
    return 0;
}