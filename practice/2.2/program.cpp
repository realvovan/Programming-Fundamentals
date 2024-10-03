/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 2.2
*/

#include "iostream"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "iomanip"

using std::vector;
using std::cout;
using std::setw;

void task1() {
    // Задано множину послідовностей значень A[m,n].
    // Замінити в кожній послідовності A[i] мінімальні значення на
    // суму елементів цієї послідовності.
    cout << "====================\nTask 1\n";
    const int ROW_COUNT = 5;
    const int COLUMN_COUNT = 10;
    vector<vector<int>> A(ROW_COUNT);
    cout << "Intial vector:\n";
    for(int i = 0; i < ROW_COUNT; i++) {
        cout << "Sequence " << i << ": ";
        A[i].resize(COLUMN_COUNT);
        for(int j = 0; j < COLUMN_COUNT; j++) {
            A[i][j] = rand() % 100;
            cout << setw(3) << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Updated vector:\n";
    for(int i = 0; i < ROW_COUNT; i++) {
        cout << "Sequence " << i << ": ";
        int minIndex = 0;
        int sum = 0;
        for(int j = 0; j < COLUMN_COUNT; j++) {
            if(A[i][j] < A[i][minIndex]) minIndex = j;
            sum += A[i][j];
        }
        A[i][minIndex] = sum;
        for(int j : A[i]) cout << setw(3) << j << " ";
        cout << "\n";
    }
}

int main() {
    srand(time(NULL));
    task1();
    return 0;
}