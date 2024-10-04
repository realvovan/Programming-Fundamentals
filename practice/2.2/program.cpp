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
#include "algorithm"

using std::vector;
using std::cout;
using std::setw;

//populates the given vector with random integers in range [1,19] and prints it in the output
void populateVector(vector<int> &sequence) {
    for(int i = 0; i < sequence.size(); i++) {
        sequence[i] = rand() % 20;
        cout << setw(2) << sequence[i] << " ";
    }
    cout << "\n";
}

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

void task2() {
    // Задано дві послідовності значень A[n] і B[m]. Замінити в A[n] входження значень із B[m] на добуток елементів
    // підпослідовності B[m]
    cout << "====================\nTask 2\n";
    const int VECTOR_SIZE = 5;
    int product = 1;
    vector<int> A(VECTOR_SIZE),B(VECTOR_SIZE);
    cout << "Initial vector A: ";
    populateVector(A);
    cout << "Initial vector B: ";
    populateVector(B);
    for(int i : B) product *= i;
    cout << "The product of elements of vector B is " << product << "\n";
    for(int i = 0; i < VECTOR_SIZE; i++) {
        //check if vector B contains elemnt A[i]
        if(std::find(B.begin(),B.end(),A[i]) != B.end()) A[i] = product;
    }
    cout << "Updated vector A: ";
    for(int i : A) {
        cout << setw(2) << i << " ";
    }
    cout << "\n";
}

int main() {
    srand(time(NULL));
    task1();
    task2();
    return 0;
}