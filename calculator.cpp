#include "BigInt.h"
#include <stack>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <sstream> // several of these not needed either, included just in case while trying various implementations

int prec(const char c) // returns precedence of operator
{
    int temp = 0;
    if(c == '+' || c == '-')
    {
        temp = 0;
    }
    else if(c == '*')
    {
        temp = 1;
    }
    return temp;
}


bool isOperator(const char input) // returns true if char is operator, returns false if char is not, same concept as isDigit
{
    if(input == '+' || input == '-' || input == '*')
      {  return true;}
  else{
    return false;
    }
}

 std::string infixToPostfix(const std::string &infix)
{
  std::stack<char> opStack;
  std::string postFixString;
  postFixString = " ";
  unsigned int i;
  char curOp;
  for (i=0;i<infix.length();i++)
  {
    //isdigit(infix[i]) || infix[i] == ' ' )
    if((isdigit(infix[i]))	|| (infix[i] == ' ') || (infix[i] == '\t') || (infix[i] == '\n'))
    {
      postFixString = postFixString + infix[i];
    }
    else if (isOperator(infix[i]))
    {
      curOp = infix[i];
      while ((!opStack.empty()) && (opStack.top() != '(') && (prec(opStack.top()) >= prec(curOp)))
      {
        postFixString = postFixString + opStack.top();
        opStack.pop();
      }
      opStack.push(curOp);
    }
    else if (infix[i] == '(')
    {
      opStack.push('(');
    }
    else if (infix[i] == ')')
    {
      while (!opStack.empty())
      {
        if (opStack.top() == '(')
        {
          opStack.pop();
          break;
        }
        else
        {
          postFixString = postFixString + opStack.top();
          opStack.pop();
        }
      }
    }
  }
  while (!opStack.empty())
  {
    postFixString = postFixString + opStack.top();
    opStack.pop();
  }
  return postFixString;
} 


ds::BigInt evaluatePostfix(const std::string &postfix)
{
  std::stack<ds::BigInt> Num;
  std::string SubString;
  ds::BigInt Num1("");
  ds::BigInt Num2("");
  unsigned int i;
  for (i = 0; i <= postfix.length() - 1; i++)
  {
    if (isdigit(postfix[i]))
    {
      SubString += postfix[i];
      if (!isdigit(postfix[i+1]))
      {
        ds::BigInt SubNum(SubString);
        Num.push(SubNum);
        SubString = "";
      }
    }
    if (isOperator(postfix[i]))
    {
      ds::BigInt SubNum(SubString);
      Num1 = Num.top();
      Num.pop();
      Num2 = Num.top();
      Num.pop();
      switch (postfix[i])
      {
        case '+':
          SubNum = Num1 + Num2;
          break;
        case '-':
          SubNum = Num1 - Num2;
          break;
        case '*':
          SubNum = Num1 * Num2;
          break;
      }
      Num.push(SubNum);
    }
  }
  return Num.top();
}






  