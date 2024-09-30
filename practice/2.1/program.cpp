/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 2.1
*/

#include "iostream"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "iomanip"

using namespace std;

void minAndMaxIndices(vector<vector<int>> sequence) {
    //Завдання 1
    //Задано множину послідовностей значень A[m,n], де m – номер послідовності, а n – кількість
    //елементів у тій послідовності. Знайти індекси розміщення мінімального значення в множині.
    cout << "=================================\nTask 1\n";
    int minIndexM = 0;
    int minIndexN = 0;
    for(int i = 0; i < sequence.size(); i++) {
        for(int j = 0; j < sequence[i].size(); j++) {
            if(sequence[i][j] < sequence[minIndexM][minIndexN]) {
                minIndexM = i;
                minIndexN = j;
            }
        }
    }
    cout << "The smallest number is " << sequence[minIndexM][minIndexN] << " in sequence " << minIndexM << " at position " << (minIndexN + 1) << "\n";
}

void largestNegativeNum(vector<vector<int>> sequence) {
    //Завдання 2
    //Задано множину послідовностей значень A[m,n], де m – номер послідовності, а n – кількість елементів
    //тій послідовності. Знайти максимальне від’ємне значення в множині.
    cout << "=================================\nTask 2\n";
    int largest = 0;
    for(vector<int> i : sequence) {
        for(int j : i) {
            if(j < 0 && (largest == 0 || j > largest)) largest = j;
        }
    }
    if(largest == 0) {
        cout << "No negative numbers in the sequence!\n";
        return;
    }
    cout << "The largest negative number is " << largest << "\n";
}

void smallestPositive(vector<vector<int>> sequence) {
    // Завдання 3
    // Задано множину послідовностей значень A[m,n], де m – номер послідовності, а n – кількість
    // елементів у m-тій послідовності. Знайти мінімальне додатне значення в множині.
    cout << "=================================\nTask 3\n";
    int smallest = 0;
    for(vector<int> i : sequence) {
        for(int j : i) {
            if(j > 0 && (smallest == 0 || j < smallest)) smallest = j;
        }
    }
    if(smallest == 0) {
        cout << "No positive numbers in the sequence!\n";
        return;
    }
    cout << "The smallest positive number is " << smallest << "\n";
}

int main() {
    int m,n;
    cout << "Enter the number of sequnces: ";
    cin >> m;
    cout << "Enter the length of the sequences: ";
    cin >> n;
    if(m < 1 || n < 1) {
        cout << "Number of sequences or elements in the sequences must be greater or equal to one";
        return 0;
    }
    srand(time(NULL));
    vector<vector<int>> A(m);
    //initialize the 2d vector with random values
    for(int i = 0; i < A.size(); i++) {
        cout << "Sequence " << i << ": ";
        A[i].resize(n);
        for(int j = 0; j < A[i].size(); j++) {
            A[i][j] = (rand() % 200) - 100;
            cout << setw(2) << A[i][j] << " ";
        }
        cout << "\n";
    }

    minAndMaxIndices(A);

    largestNegativeNum(A);

    smallestPositive(A);    
    return 0;
}