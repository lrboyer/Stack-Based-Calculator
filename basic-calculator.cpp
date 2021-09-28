#include "basic-calculator.h"

using namespace std;

int main() {
    int input;

    cout << "---   This is a basic 5 operation calculator   ---" << endl;
    cout << "---   I can do addition, subtraction, multiplication, division, and modulo   ---" << endl;
    cout << "---   You can also use parenthesis   ---" << endl;
    cout << "---   Example of correct syntax for infix: 2 + 3 * 4 + ( 5 - 6 + 7 ) % 8   ---" << endl;
    cout << "---   Example of correct syntax for postfix: 2 3 4 * + 5 6 - 7 + 8 * +  ---" << endl << endl << endl;


    while (input != 3) {
        input = menu();

        switch(input) {
            case 1: //calculates expression infix
                calculateExpressionInfix();
            break;

            case 2: //calculates expression postfix way
                calculateExpressionPostfix();
            break;

            case 3: //quits
                cout << "---      Have a nice day!      ---" << endl;
            break;

            default: //incase they don't choose 1 or 2
                cout << "---     Please enter a valid input     ---" << endl << endl;
            break;
        }
    }
}