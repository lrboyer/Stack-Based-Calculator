#include <iostream>
#include <string>
#include <stack>
#include "infixToPostfix.h"
#include "calculate.h"

#pragma once
using namespace std;

int menu() {
    int input;

    cout << "---   Press 1 to enter an expression infix notation   ---" << endl;
    cout << "---   Press 2 to enter an expression postfix notation   ---" << endl;
    cout << "---           Press 3 to exit          ---" << endl;
    //may add more functions
    
    cout << endl << "--> ";
    cin >> input;
    cout << endl;

    return input;
}

void calculateExpressionInfix() {
    int result, postfixLength;
    string expression, buffer;

    cout << "---   Please enter an expression: " << endl << "-->   ";
    cin.ignore();
    getline(cin, expression);
    cout << endl;

    if (expression.size() < 3) {
        cout << "---   Expression must have proper format!" << endl << endl;
        return;
    }

    for (long unsigned int i = 0; i < expression.size(); i++) {
        if ((expression[i] > 48 && expression[i] < 58) && expression[i+1] == ' ' && expression[i+2] == ' ') {
            cout << "---   Expression must have proper format!" << endl << endl;
            return;
        }
        else if (expression[i] == ' ' &&  expression[i+1] == ' ') {
            cout << "---   Expression must have proper format!" << endl << endl;
            return;
        }
    }
        
    string infix[expression.size()];
    string postfix[expression.size()];
    int j = 0;
    
    for (long unsigned int i = 0; i < expression.size(); i++) {
        if(expression[i] != ' ') {
            buffer += expression[i];
        }
        else {
            infix[j] = buffer;
            j++;
            buffer.clear();
        }
    }
    infix[j] = buffer;
    j++;
    
    postfixLength = infixToPostfix(infix, j, postfix);
    
    result = calculatePostfixExpression(postfix, postfixLength);

    cout << "-->   " << result << "   ---" << endl << endl;
    
}

void calculateExpressionPostfix() {
    int result;
    string expression, buffer;

    cout << "---   Please enter an expression: " << endl << "-->   ";
    cin.ignore();
    getline(cin, expression);
    cout << endl;

    if (expression.size() < 3) {
        cout << "---   Expression must have proper format!" << endl << endl;
        return;
    }

    for (long unsigned int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' &&  expression[i+1] == ' ') {
            cout << "---   Expression must have proper format!" << endl << endl;
            return;
        }
        else if ((expression[i] > 48 && expression[i] < 58) && expression[i+1] == ' ' && expression[i+2] == ' ') {
            cout << "---   Expression must have proper format!" << endl << endl;
            return;
        }
    }
        
    string postfix[expression.size()];
    int j = 0;
    
    for (long unsigned int i = 0; i < expression.size(); i++) {
        if(expression[i] != ' ') {
            buffer += expression[i];
        }
        else {
            postfix[j] = buffer;
            j++;
            buffer.clear();
        }
    }
    postfix[j] = buffer;
    j++;
    
    result = calculatePostfixExpression(postfix, j);

    cout << "-->   " << result << "   ---" << endl << endl;
    
}