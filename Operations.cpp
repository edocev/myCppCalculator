// Operations.cpp
#include "Operations.h"
#include <iostream>

int Operations::add(int a, int b) {
    return a + b;
}

int Operations::subtract(int a, int b) {
    return a - b;
}

int Operations::multiply(int a, int b) {
    return a * b;
}

float Operations::divide(int a, int b) {
    if (b != 0) {
        return static_cast<float>(a) / b;
    } else {
        std::cout << "Error: Division by zero is undefined." << std::endl;
        return 0.0f;
    }
}

int Operations::fibonacci(int n) {
    if (n <= 0) {
        std::cout << "Error: Invalid input for Fibonacci calculation." << std::endl;
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int Operations::factoriel(int n) {
    if (n <= 0) {
        std::cout << "Error: Invalid input for factorial calculation." << std::endl;
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return n * factoriel(n - 1);
    }
}