#include <iostream>

long long fib(int n) {
    int x, y;
    
    if (n < 2) {
        return n;
    }

    x = fib(n-1);
    y = fib(n-2);

    return (x + y);
}

int main() {
    int NW = 50;
    long long res = fib(NW);

    std::cout << "Result = " << res << std::endl;

    return 0;
}