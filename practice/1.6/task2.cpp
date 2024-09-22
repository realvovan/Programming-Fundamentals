/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 1.6
*/

#include "iostream"
#include "vector"
#include "stdlib.h"
#include "time.h"

using std::cout;
using std::vector;

//Задано дві послідовності, які скалдаються з 0 та 1. Склаасти специфікацію для моделювання операцій XOR

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the length of a sequence: ";
    std::cin >> n;
    if(n < 1) {
        cout << "Number of elements must be greater than 0\n";
        return 0;
    }
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> xorVector(n);
    //populate the sequence with random values and print it out
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        v1[i] = rand() % 2;
        v2[i] = rand() % 2;
        xorVector[i] = v1[i] ^ v2[i];
    }
    cout << "Sequence 1:                              ";
    printVector(v1);
    cout << "Sequence 2:                              ";
    printVector(v2);
    cout << "XOR specification for the two sequences: ";
    printVector(xorVector);
    return 0;
}