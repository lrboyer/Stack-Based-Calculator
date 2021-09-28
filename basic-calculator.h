#include <iostream>
#include <string>
#include <stack>

bool isNum(char c) {
    if ((c > 48) && (c < 58)) {
        return true;
    }
    else {
        return false;
    }
}

//this changes the string value into a char
//so a single letter string is not just a char
char convert(string s) {
    return s.c_str()[0];
}

//this gets the level of precedence for each case and returns it
//higher the precedence the higher the return
int precedence(char val) {
   if (val == '+' || val == '-') {
      return 1; //precedence of + or - is 1
   }
   else if (val == '*' || val == '/' || val == '%') {
      return 2; //precedence of * or / or % is 2
   }
   else {
      return 0;
   }
}

//this does the converting infix to postfix form and returns the length of the postfix string
//returns 0 if infix uses incorrect parenthesis usage
int infixToPostfix(string infix[], int length, string postfix[]) {
    int leftParen = 0;
    int rightParen = 0;

    //this adds up the total number of left and right paren to compare them later
    for (int i = 0; i < length; i++) {
        if (infix[i].compare("(") == 0) {
            leftParen++;
        }
        else if (infix[i].compare(")") == 0) {
            rightParen++;
        }
    }
    if (leftParen != rightParen) { //if the number of left and right parenthesis is even it should have correct parenthesis usage
        return 0;
    }
    else {
        stack< char > postfixStack; //makes stack of chars
        postfixStack.push('@'); //to prevent trying access top when stack is empty have dummy value
        int postfixPos = 0; //to keep track of where to put nums into the postfix
                            //the lengths of infix and postfix are diff so you need to keep track of postfix size to know
                            //where to put it and to not skip an array position

        for (int i = 0; i < length; i++) {
            if (isNum(convert(infix[i]))) { //for when infix is a num
                postfix[postfixPos++] = infix[i]; //after adding the val to postfix increment the counter so next time
                                                  //you add it puts it in the right spot
            }
            else if (infix[i].compare("(") == 0) { //when infix is ( it pushes ( onto the stack
                postfixStack.push('(');
            }
            else if (infix[i].compare(")") == 0) { //when infix is ) it adds everything on the stack to postfix until it hits (
                while (postfixStack.top() != '@' && (postfixStack.top() != '(')) {
                    postfix[postfixPos++] = postfixStack.top(); //add to postfix and pop until ( is found
                    postfixStack.pop();
                }
                postfixStack.pop(); //removes ( from stack
            }
            else {
                if (precedence(convert(infix[i])) > precedence(postfixStack.top())) { //for when infix is an operator it compares the stack precedence to infix
                    postfixStack.push(convert(infix[i])); //push onto stack if precedence is higher than top of stack
                }
                else { //if the stack precedence is higher it adds everything that is lower precedence to postfix
                    while ((postfixStack.top() != '@') && (precedence(convert(infix[i])) <= precedence(postfixStack.top()))) {
                        postfix[postfixPos++] = postfixStack.top(); //add to postfix and pop until higher precedence is found
                        postfixStack.pop();
                    }

                    postfixStack.push(convert(infix[i]));
                }
            }
        }
        
        while (postfixStack.top() != '@') { //adds the remainder of the stack into postfix
            postfix[postfixPos++] = postfixStack.top(); //add stack to string and pop until stack is not empty
            postfixStack.pop();
        }
            
        return postfixPos; //returns the size of postfix
    }  
}

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
    int num = 0;

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