#include "BigInt.h"
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector> // several of these not needed, included just in case

namespace ds {

BigInt::BigInt(const std::string &val) {
  // If use STL: store the big integer `val` in `digits`
  for (size_t j = 0; j < val.size(); j++) {
    digits.append(val[j] - '0');
  }
}

std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
  // If use STL: put `bi.digits` to `os`
  for (int i = 0; i < bi.digits.length(); i++)
    os << bi.digits.getValueAt(i);
  return os;
}

BigInt BigInt::operator=(const BigInt &other) // overloaded operator to aid in everything, including * plus calculator.cpp
{
  this->digits.clear();
  for (int i = 0; i <= other.digits.length()-1; i++)
  {
    this->digits.append(other.digits.getValueAt(i));
  } 
 return *this; 
}


BigInt BigInt::operator+(const BigInt &other) const {
  // TODO: return the *sum* of this BigInt and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Addition
  // E.G.: 456 + 1123 = 1579
  int carry = 0;
  std::stack<int> digitStack;
  int i = digits.length() - 1;
  int j = other.digits.length() - 1;

  while (i >= 0 || j >= 0) {
    int thisDig = i >= 0 ? digits.getValueAt(i) : 0;
    int otherDig = j >= 0 ? other.digits.getValueAt(j) : 0;
    int sum = thisDig + otherDig + carry;

    digitStack.push(sum % 10);
    carry = sum / 10;

    --i;
    --j;
  }

  if (carry > 0)
    digitStack.push(carry);

  BigInt res("");
  while (!digitStack.empty()) {
    res.digits.append(digitStack.top());
    digitStack.pop();
  }
  return res;
  BigInt sum("");
  return sum;
}

BigInt BigInt::operator-(const BigInt &other) const {
  // TODO: return the *absolute difference* between this and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Absolute_difference
  // E.G.: 456 - 1123 = 667
  if (digits.length() < other.digits.length()) { // this is first test for islessthan(), if length is smaller then it is simply less than
    return other - *this;
  }
  if (digits.length() == other.digits.length()) // further testing
  {
    for(int i = 0; i <= digits.length(); i++)
    {
      if (other.digits.getValueAt(i) > digits.getValueAt(i)) // compares EACH digit 
      {
        return other - *this;
      }
      else if(other.digits.getValueAt(i) < digits.getValueAt(i))
      {
        break;
      }
    }
  }
  int carry = 0;
  std::stack<int> digitStack;
  int i = digits.length() - 1;
  int j = other.digits.length() - 1;

  while (i >= 0 || j >= 0) {
    int thisDig = i >= 0 ? digits.getValueAt(i) : 0;
    int otherDig = j >= 0 ? other.digits.getValueAt(j) : 0;
    int sub = thisDig - otherDig - carry;

    if (sub < 0)
     {
      sub += 10;
      carry = 1;
     }
     else
      {
      carry = 0;
      }

    digitStack.push(sub);

    i = i - 1;
    j = j - 1;
  }

  // remove leading zeros
  while (!digitStack.empty()) {
    if (digitStack.top() != 0)
    {
      break;
    }
    digitStack.pop();
  }

  BigInt res("");
  while (!digitStack.empty()) {
    res.digits.append(digitStack.top());
    digitStack.pop();
  }
  return res;
}

BigInt BigInt::operator*(const BigInt &other) const {
  // TODO: return the *product* of this BigInt and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Multiplication
  // E.G.: 456 * 1123 = 512088

BigInt Total("");
  std::stack<int> digitStack;
  int i,j,IndexI,IndexJ;
  IndexI = 0;
  IndexJ = 0;
  for (i=digits.length() - 1; i >=0;i--)
  {
    int thisDig;
    thisDig = digits.getValueAt(i);
    for (j =  other.digits.length() - 1; j >=0; j--)
    {
      int otherDig;
      otherDig = other.digits.getValueAt(j);
      int p;
      std::string pro;
      p = thisDig*otherDig;
      pro = std::to_string(p);
      if (p != 0)
      {
        for (int l=0;l < IndexI + IndexJ; l++)
        {
          pro = pro + "0";
        }
      }
      BigInt Product(pro);
      IndexJ = IndexJ + 1;
      Total = Total + Product;
    }
    IndexJ = 0;
    IndexI = IndexI + 1;
  }
  return Total;
} 
} // namespace ds



      



