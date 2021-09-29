#include <iostream>
#include <string>
#include <stack>

#pragma once
using namespace std;

//returns true if input is a num and false else
bool isNum(string s) {
    if ((s[0] > 48) && (s[0] < 58)) {
        return true;
    }
    else {
        return false;
    }
}

//calculates the expression using the inputed nums and ops
//returns a string containing the answer
string calc(string op1, string op2, char symbol) {
    long long int num = 0;

    switch (symbol) {
        case '+' :
            num = (stoi(op1) + stoi(op2));
            break;
        case '-' :
            num = (stoi(op1) - stoi(op2));
            break;
        case '*' :
            num = (stoi(op1) * stoi(op2));
            break;
        case '/' :
            num = (stoi(op1) / stoi(op2));
            break;
        case '%' :
            num = (stoi(op1) % stoi(op2));
            break;
        default :
            return 0;
    }

    //converts the int back to string
    return to_string(num);
}

int calculatePostfixExpression(string expression[], int length)
{   
    //both ifs check for correct usage of post fix expression
    if (length == 1 && isNum(expression[0])) {
        return stoi(expression[0]);
    }
    if ((length < 1) || (!isNum(expression[0]) || !isNum(expression[1]))) {
        return 0;
    }

    stack< string > stk;
    string op1, op2;

    for (int i = 0; i < length; i++) {
        if (isNum(expression[i])) { //val is a number
            stk.push(expression[i]);
        }
        else { //the value is an operand
            op2 = stk.top(); //gets second num
            stk.pop();
            op1 = stk.top(); //gets first num
            stk.pop();
            stk.push(calc(op1, op2, expression[i][0])); //sends nums and op to be calculated then pushes result to stack

            //if the stack only has the sol and it is the end of the expression
            if (++i == length && stk.size() == 1) {
                return stoi(stk.top());
            }
            i--; //if not decrement i and keep going
            //have to decrement bc the if statement increments i and need to decrement bc its false
        }
    }

    return 0;
}