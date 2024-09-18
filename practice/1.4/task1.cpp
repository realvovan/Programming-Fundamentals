/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 1.5
*/
#include "iostream"

using std::cout;
using std::cin;

//Задано ціле число N. Знайти середнє арифметичне всіхнепарних чисел на проміжку від 0 до N.
int main() {
    int sum = 0, count = 0;
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    if(n <= 0) {
        cout << "Positive integer expected, got " << n << "\n";
        return 0;
    }
    for(int i = 1; i <= n; i += 2) {
        sum += i;
        count++;
    }
    float average = static_cast<float>(sum)/count;
    //flaot average = ceil(static_cast<float>(n) / 2)
    //alternatively you can calculate the average like that without needing to use a for loop (+need to include "math.h")
    cout << "The average of odd numbers in range 0 to " << n << " is " << average << "\n";
    return 0;
}