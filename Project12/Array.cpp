#include "Array.h"
#include <iostream>

int main() {
    Array arr1(5);
    for (size_t i = 0; i < arr1.getSize(); ++i) {
        arr1[i] = static_cast<int>(i + 1);
    }

    Array arr2 = std::move(arr1);

    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr1: ";
    for (size_t i = 0; i < arr1.getSize(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    Array arr3(3);
    arr3 = std::move(arr2);

    std::cout << "arr3: ";
    for (size_t i = 0; i < arr3.getSize(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
