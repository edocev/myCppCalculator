// Paint.cpp
#include "Paint.h"
#include <iostream>

void Paint::resultsPaint(int result) {
    std::string resultStr = std::to_string(result);
    paintBox(resultStr);
}

void Paint::resultsPaint(float result) {
    std::string resultStr = std::to_string(result);
    paintBox(resultStr);
}

void Paint::paintBox(const std::string& resultStr) {
    int boxWidth = resultStr.length() + 4;

    for (int i = 0; i < boxWidth; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    std::cout << "| " << resultStr << " |" << std::endl;

    for (int i = 0; i < boxWidth; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}