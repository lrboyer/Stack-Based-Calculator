#include <iostream>
#include <string>
#include <stack>
#include "infixToPostfix.h"
#include "calculate.h"

#pragma once
using namespace std;

int checkInput(const string in) {

    if (in.size() < 3)
            return -1;
    
    for (long unsigned int i = 0; i < in.size(); i++) {
        if (in[i] == ' ' &&  in[i+1] == ' ')
            return -1; //not proper input
    }
    for (long unsigned int i = 0; i < in.size(); i++) {
        if (isNum(in[i]) && in[i+1] == ' ' && isNum(in[i+2])) 
            return 2; //2 means an postfix operation is needed
    }

    return 1; //1 means infix operation is needed
}

void calculateExpressionInfix(const string expression) {
    int postfixLength;
    long long int result;
    string buffer;
        
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

    cout << "-->   " << result << endl << endl;
    
}

void calculateExpressionPostfix(const string expression) {
    int result;
    string buffer;
        
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

    cout << "-->   " << result << endl << endl;
    
}