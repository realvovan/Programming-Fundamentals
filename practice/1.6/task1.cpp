/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 1.6
*/
#include "iostream"
#include "bitset"

//Задано ціле значення А. Визначити, яких бітів (0 чи 1) більше в його двійковому поданні
int main() {
    int zeros = 0,
        ones = 0,
        a;
    std::cout << "Enter an integer: ";
    std::cin >> a;
    for(int i = 0; i < sizeof(int) * 8; i++) {
        int mask = 1 << i;
        (a & mask) == 0 ? zeros++ : ones++;
    }
    std::cout << "There are " << ones << " 1s and " << zeros << " 0s in number " << a << "(0x" << std::bitset<sizeof(int) * 8>(a) << ")\n";
    return 0;
}