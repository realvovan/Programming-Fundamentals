/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 1.5
*/

#include "iostream"
#include "math.h"

using std::cout;
using std::cin;

//Задано геометричну прогресію (перший член – b1, знаменник прогресії – q). Знайти середнє арифметичне перших n елементів прогресії.
int main() {
    float b1,q;
    int n;
    cout << "Enter the number of elements in a geometric progression (n): ";
    cin >> n;
    cout << "Enter the first element in the geometric progression (b1): ";
    cin >> b1;
    cout << "Enter the common ratio of the geometric progression (q): ";
    cin >> q;
    //formula for the sum of n elements of a geometric progression S = b1*(pow(q,n)-1)/(q-1)
    float average = b1*(pow(q,n)-1)/(q-1)/n;
    cout << "The average of the first " << n << " elements of the geometric progression is " << average << "\n";
    return 0;
}