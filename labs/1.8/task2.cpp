/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.8
*/

#include "iostream"
//2. Підрахунок кількості одиничних бітів
int main() {
    int ones = 0,
        n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    for(int i = 0; i < sizeof(int) * 8; i++) {
        int mask = 1 << i;
        if((n & mask) != 0) ones++;
    }
    std::cout << "Number " << n << " has " << ones << " 1s bits\n";
    return 0;
}