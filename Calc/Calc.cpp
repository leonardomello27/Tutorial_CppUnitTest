
#include <iostream>
#include <stdexcept>

int soma(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        
        throw std::invalid_argument("Divisão por zero."); // Lança uma exceção
    }

    return a / b;
}