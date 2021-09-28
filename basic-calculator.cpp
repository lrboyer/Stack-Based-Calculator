#include "basic-calculator.h"

using namespace std;

int main() {
    char input = '1';
    string expression;
    int result;

    cout << "This is a basic 5 operation calculator" << endl;
    cout << "I can do addition, subtraction, multiplication, division, and modulo" << endl;
    cout << "You can also use parenthesis" << endl;
    cout << "Example of correct syntax: 2 + 3 * 4 + ( 5 - 6 + 7 ) % 8" << endl;

    while (input != 'q') {
        cout << "Press 'q' to exit" << endl;
        cout << "Press '1' to enter an expression" << endl;
        //may add more functions

        cin >> input;

        if (input == '1')  {
            cout << "Please enter an expression: ";
            cin >> expression;
            string infix[expression.size()];
            string postfix[expression.size()];
            int postfixLength;
            for (int i = 0; i < expression.size(); i++) {
                infix[i] = expression[i];
            }
            postfixLength = infixToPostfix(infix, expression.size(), postfix);
            result = calculatePostfixExpression(postfix, postfixLength);
            cout << result << endl;
        }
    }
}