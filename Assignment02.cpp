#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// Function to check Operator Precedence
int prec(char c) {
    if (c == '^' || c == '$') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;    
}

// Function to check associativity
char associativity(char c) {
    if (c == '^' || c == '$') return 'R'; // Right associative
    return 'L'; // Left associative for other operators
}

// Function to convert expression from infix to postfix
void infixToPostfix(const string& s) {
    string postfix;
    int len = s.length();
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; ++i) {
        char c = s[i];

        if (isalnum(c)) {
            // Operand (letters and digits) goes to postfix
            postfix += c;
        } else if (c == '(') {
            // Push '(' onto stack
            stack[++stackIndex] = c;
        } else if (c == ')') {
            // Pop until '(' is found
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                postfix += stack[stackIndex--];
            }
            // Pop '(' from stack
            if (stackIndex >= 0 && stack[stackIndex] == '(') {
                --stackIndex;
            }
        } else {
            // Operator
            while (stackIndex >= 0 && stack[stackIndex] != '(' &&
                   (prec(c) < prec(stack[stackIndex]) ||
                    (prec(c) == prec(stack[stackIndex]) && associativity(c) == 'L'))) {
                postfix += stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop remaining operators from stack
    while (stackIndex >= 0) {
        postfix += stack[stackIndex--];
    }

    // Print the postfix expression
    cout << "Postfix expression: " << postfix << endl;
}

int main() {
    cout << "Enter an expression to convert from infix to postfix: " << endl;
    string exp;
    getline(cin, exp); // Read the entire line of input
    infixToPostfix(exp);
    return 0;
}

