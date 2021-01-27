#include "BigInt.h"
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
//#include <functional>
#include <vector> // several of these not needed, included just in case

namespace ds {

BigInt::BigInt(const std::string &val) {
  // If you use STL: store the big integer `val` in `digits`
  for (size_t j = 0; j < val.size(); j++) {
    digits.append(val[j] - '0');
  }
}

std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
  // If you use STL: put `bi.digits` to `os`
  for (int i = 0; i < bi.digits.length(); i++)
    os << bi.digits.getValueAt(i);
  return os;
}


/*std::vector<int> add(std::vector<int>& lhs, std::vector<int>& rhs) // function to add for * operator // not needed, implementation had several bugs
{
  int sizeDiff = (int)lhs.size() - (int)rhs.size(); 
  //int sizeDiff = lhs.size() - 
  if(sizeDiff < 0)
  {
    lhs.insert(lhs.begin(), abs(sizeDiff), 0);
  }
  else if(sizeDiff < 0)
  {
    rhs.insert(rhs.begin(), abs(sizeDiff), 0);
  }
  std::vector<int> resultVect;
  int carry = 0;
  for(int i = lhs.size() - 1; i >=0; --i)
  {
    int result = lhs[i] + rhs[i] + carry;
    carry = result / 10;
    result %= 10;
    resultVect.insert(resultVect.begin(), result);
  }
  if ( carry !=0) \
  {
      resultVect.insert(resultVect.begin(), carry);
  }
  return resultVect;

} */
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
/*int unitPlace = 0; // Keeps track of how many zeros to add 
        std::vector<int> totalVect; // Accumulated value after each addition
        std::vector<int> resultVect; // Result of multiplication

        for (int i = other.digits.length() - 1; i >= 0; --i, unitPlace++)
        {
            int carry = 0;
            for (int k = 0; k < unitPlace; ++k) resultVect.push_back(0);

            for (int j = digits.length() - 1; j >= 0; j--)
            {
                int result = other.digits.getValueAt(i) * digits.getValueAt(j)+ carry;
                carry = result / 10;
                result %= 10;

                resultVect.insert(resultVect.begin(), result);
            }
            resultVect.insert(resultVect.begin(), carry);
            totalVect = add(totalVect, resultVect); // Add sub-result
            resultVect.clear();
        }

        // Strip leading zeros
        for (long unsigned int i = 0; i < totalVect.size(); ++i) {
            if (totalVect[i] == 0) totalVect.erase(totalVect.begin() + i);
            else break;
        }

  BigInt prod("");
  for(long unsigned int i = 0; i < totalVect.size(); i++)
  {
    prod.digits.append(totalVect[i]);
  }
  return prod;

}*/

} // namespace ds



      



