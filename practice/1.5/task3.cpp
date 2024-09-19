/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 1.5
*/

#include "iostream"
#include "stdlib.h"
#include "time.h"

using std::cout;
using std::cin;

//Задано послідовність значень А[n]. Знайти найбільше і найменше значення та поміняти їх місцями.

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cout << "Enter the length of sequence: ";
    cin >> n;
    if(n < 1) {
        cout << "Number of elements must be greater than 0";
        return 0;
    }
    int *arr = new int[n];
    srand(time(NULL)); // set the seed of the random number generator
    //now populate the array with random number and print it in the output
    for(int i = 0; i < n; i++) { 
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << "\n";
    int minIndex = 0;
    int maxIndex = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < arr[minIndex]) minIndex = i;
        if(arr[i] > arr[maxIndex]) maxIndex = i;
    }
    cout << "Largest value: " << arr[maxIndex] << "\nSmallest value: " << arr[minIndex] << "\n";
    swap(arr[minIndex],arr[maxIndex]);
    cout << "Updated array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}