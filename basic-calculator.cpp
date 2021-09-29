#include "basic-calculator.h"

using namespace std;

int main() {
    int check;
    string expression;

    cout << "---   This is a basic 5 operation calculator" << endl;
    cout << "---   I can do addition, subtraction, multiplication, division, and modulo" << endl;
    cout << "---   I only take in positive integers and have integer precision" << endl;
    cout << "---   To input a negative number put in x is the number you want negative: ( ( 1 - 2 ) * x )" << endl << endl;

    cout << "---   I can take inputs in infix or postfix form" << endl;
    cout << "---   Example of correct syntax for infix: 2 + 3 * 4 + ( 5 - 6 + 7 ) % 8" << endl;
    cout << "---   Example of correct syntax for postfix: 2 3 4 * + 5 6 - 7 + 8 * + " << endl << endl;


    while (expression != "q") {
        cout << "---   Enter q to quit" << endl;
        cout << "---   Enter an expression: ";
        
        getline(cin, expression);
        
        if (expression == "q") {
            cout << endl << "---   Have a nice day!" << endl;
            cout << "---   Made by Lucas Boyer" << endl;

        }
        else {
            check = checkInput(expression);

            if (check == -1) {
                cout << "---   Expression must have proper format!" << endl << endl;
            }
            else if (check == 1) 
                calculateExpressionInfix(expression);
            else //check == 2
                calculateExpressionPostfix(expression);
        }
    }
}