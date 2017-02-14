//
//  eval.cpp
//  Maze
//
//  Created by Junnan Liu on 2/7/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

// convert infix to postfix!

// binary boolean operators & (meaning and) and | (meaning inclusive or), the unary boolean operator ! (meaning not), parentheses, and operands (with blanks allowed for readability)
//
// ! has higher precedence than &, which has higher precedence than |, and the operators & and | associate left to right

// error check
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int opPrecedence(char c);
bool checkValid(string infix);
int evaluate(string infix, const bool values[], string& postfix, bool& result)
// Evaluates a boolean expression
// Postcondition: If infix is a syntactically valid infix boolean
//   expression, then postfix is set to the postfix form of that
//   expression, result is set to the value of the expression (where
//   in that expression, each digit k represents element k of the
//   values array), and the function returns zero.  If infix is not a
//   syntactically valid expression, the function returns 1.  (In that
//   case, postfix may or may not be changed, but result must be
//   unchanged.)
{
    if (!checkValid(infix))
        return 1;
    postfix = "";  // Initialize postfix to empty
    stack <char> operatorStack;  // Initialize the operator stack to empty
    
    for (int i = 0; i < infix.size(); i++)  // For each character ch in the infix string
    {
        char ch = infix[i];

        switch (ch)
         {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix += ch;
                break;
            case '(':
                operatorStack.push(ch);
                break;
            case '!':
                operatorStack.push(ch);
                break;
            case ')':  // // pop stack until matching '('
                while (operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
            case '|':
            case '&':
                while (!operatorStack.empty() && operatorStack.top() != '(' && opPrecedence(ch) <= opPrecedence(operatorStack.top()))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            default:
                break;
        }
        
    }
    
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    
    //  the evaluation of the postfix expression
    stack<bool> operandStack;  // Initialize the operand stack to empty
    for (size_t i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            int pos = ch - '0';
            operandStack.push(values[pos]); // push the value that ch represents onto the operand stack
        }
        else
        {
            bool operand2 = operandStack.top(); // set operand2 to the top of the operand stack
            operandStack.pop();
            if (ch == '!')
            {
                operandStack.push(!operand2); // apply the operation that ch represents to operand1 and operand2, and push the result onto the stack
                continue;
            }
            bool operand1 = operandStack.top();
            operandStack.pop();
            if (ch == '|')
                operandStack.push(operand1 || operand2);
            else if (ch == '&')
                operandStack.push(operand1 && operand2);
        }
    }
    if (operandStack.size() != 1)// the operand stack will contain one item, the result of evaluating the expression
        return 1;
    result = operandStack.top();
    return 0;
}

bool checkValid(string infix) // Returns true if the infix string is valid
{
    char prevChar = '!';
    int leftParentheses = 0;  // Set beginning value
    int rightParentheses = 0;
    
    for (int i = 0; i < infix.size(); i++)
    {
        char curChar = infix[i];
        if (curChar == ' ')
            continue;
        else if (isdigit(curChar))   // If 0 <=curChar <=9, return 1, else return 0
        {
            if (isdigit(prevChar) || prevChar == ')')  // No two numbers
                return false;
        }
        else if (curChar == '!')
        {
            if (isdigit(prevChar) || prevChar == ')')  // ! can't follow digit or )
                return false;
        }
        else if (curChar == '|')
        {
            if (!isdigit(prevChar) && prevChar != ')')
                return false;
        }
        else if (curChar == '&')
        {
            if (!isdigit(prevChar) && prevChar != ')')
                return false;
        }
        
        else if (curChar == '(')
            leftParentheses++;
        else if (curChar == ')')
            rightParentheses++;
        
        prevChar = curChar;
    }
    
    if (prevChar != ')' && !isdigit(prevChar)) // Last char should be a digit or a ")"
        return false;
    
    if (leftParentheses != rightParentheses) // Number of "(" should equal number of ")"
        return false;
    return true;
}


int opPrecedence(char c)
{
    string ops = "(|&!";
    return static_cast<int>(ops.find(c)); // Returns the position in the string—-which so happens to be sorted by precedence
}

int main()
{
    bool ba[10] = {
        //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
           &&  pf == "43!03&&|"  &&  !answer);
    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    ba[2] = false;
    ba[9] = true;
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    cout << "Passed all tests" << endl;
}
