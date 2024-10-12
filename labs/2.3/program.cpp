/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Lab 2.2
*/

#include "iostream"
#include "string"
#include "stack"
#include "algorithm" //for rstd::remove_if

using std::cout;
using std::stack;
using std::string;

int getPrecedence(char op) {
    if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else if(op == '(') return 0;
    throw std::runtime_error("Invalid operator");
}

bool isDigitOrDot(char c) {
    return isdigit(c) || c == '.';
}

string infixToPostfix(const string &expression) {
    stack<char> operators;
    string postfix = "";
    for(char c : expression) {
        if(isDigitOrDot(c)) postfix += c;
        else if(c == '(') {
            operators.push('(');
        } else if(c == ')') {
            while(!operators.empty() && operators.top() != '(') {
                postfix += " ";
                postfix += operators.top();
                operators.pop(); 
            }
            operators.pop();
        } else {
            postfix += " ";
            while(!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.push(c);
        }
    }
    while(!operators.empty()) {
        postfix += " ";
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

float processPostfix(const string &expression) {
    stack<float> nums;
    string currentNum = "";
    for(char c : expression) {
        if(isDigitOrDot(c)) currentNum += c;
        else if(c == ' ') {
            if(currentNum.empty()) continue;
            nums.push(std::stof(currentNum));
            currentNum = "";
        } else {
            float val2 = nums.top();
            nums.pop();
            float val1 = nums.top();
            nums.pop();
            switch(c) {
            case '+':
                nums.push(val1+val2);
                break;
            case '-':
                nums.push(val1-val2);
                break;
            case '*':
                nums.push(val1*val2);
                break;
            case '/':
                if(val2 == 0.0) throw std::runtime_error("Cannot divide by zero!");
                nums.push(val1/val2);
                break;
            default:
                throw std::runtime_error("Invalid postfix expression!");
            }
        }
    }
    return nums.top();
}

int main() {
    string infix;
    std::getline(std::cin, infix);
    infix.erase(std::remove_if(infix.begin(),infix.end(), isspace),infix.end()); //removes whitespaces
    try {
        string postfix = infixToPostfix(infix);
        cout << "Respective postfix expression: " << postfix << "\n";
        cout << infix << "=" << processPostfix(postfix) << "\n";
    }
    catch(const std::exception& e) {
        cout << "Exception: " << e.what() << '\n';
    }
    return 0;
}