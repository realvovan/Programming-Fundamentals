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

//Задано послідовність значень А[n]. Знайти найменше значення серед додатних елементів послідовності А[n].
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
        arr[i] = rand() % 200 - 100;
        cout << arr[i] << " ";
    }
    cout << "\n";
    int min = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0 && (min == 0 || arr[i] < min)) min = arr[i];
    }
    if(min == 0) {
        cout << "No positive numbers in the sequence\n";
    } else {
        cout << "The smallest positive number in the sequence is " << min << "\n";
    }
    return 0;
}