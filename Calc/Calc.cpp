
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
        
        throw std::invalid_argument("Divis�o por zero."); // Lan�a uma exce��o
    }

    return a / b;
}