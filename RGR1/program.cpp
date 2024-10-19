/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    RGR 1
*/

//v7
// ланцюжок починається обов'язково символом "{", 
// далі може слідувати послідовність символів стандартної частини таблиці ASCII
// за виключенням символів "{" та "}", а закінчуется ланцужок обов'язково символом "}"

#include "iostream"
#include "string"

using namespace std;

bool isValidString(const string &str) {
    int len = str.length();
    if(len == 0 || str[0] != '{' || str[len - 1] != '}') return false;
    for(int i = 1; i < len - 1; i++) {
        if(
            str[i] == '{'
            || str[i] == '}'
            || static_cast<unsigned char>(str[i]) > 127 //check if the character is in the standard ASCII table
        ) return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string to be tested: ";
    getline(cin,input);
    if(isValidString(input)) cout << "Input is a valid L(V) string\n";
    else cout << "Input is NOT a valid L(V) string\n";
    return 0;
}