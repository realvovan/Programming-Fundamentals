/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.8
*/

#include "iostream"

// 1. Перевірка парності числа
int main() {
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    bool isEven = n % 2 == 0;
    // bool isEven = (n & 1) == 0; using bitwise operations
    if(isEven) std::cout << "Number " << n << " is even\n";
    else std::cout << "Number " << n << " is odd\n";
    return 0;
}