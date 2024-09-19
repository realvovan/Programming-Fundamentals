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

//Задано послідовність значень А[n] і деяке значення P. Знайти індекс першого входження Р у послідовність А[n]
int main() {
    int n,p;
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

    cout << "\nEnter number to search for: ";
    cin >> p;

    for(int i = 0; i < n; i++) {
        if(arr[i] == p) {
            cout << "The first occurance of " << p << " is at index " << i << "\n";
            return 0;
        }
    }
    cout << "Number " << p << " is not in the sequence\n";
    return 0;
}