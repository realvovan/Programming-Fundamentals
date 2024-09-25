/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 1.8
*/
#include "iostream"

using std::cout;
using std::cin;

//3. Перевірка встановленого біта на певній позиції
int main() {
    int n,pos;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Enter the position of a bit: ";
    cin >> pos;
    if(pos < 0) {
        cout << "Bit position must be greater or equal to zero\n";
        return 0;
    }
    int bitAtPos = (n & (1 << pos)) == 0 ? 0 : 1;
    cout << "Bit " << bitAtPos << " at position " << pos << "\n";
}