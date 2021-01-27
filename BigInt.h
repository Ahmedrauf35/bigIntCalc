#ifndef __BIGINT_H__
#define __BIGINT_H__

#include "LList.h"
#include <iostream>
#include <string>
#include <vector>

namespace ds {
class BigInt {
private:
  LList<int> digits;
  // You can also use STL containers, for example, `std::vector<int> digits`,
  // `std::list<int> digits`, etc.

public:
  BigInt(const std::string &val);
  BigInt(const BigInt &other) : digits(other.digits) {}

  friend std::ostream &operator<<(std::ostream &os, const BigInt &bi);
  //friend std::vector<int> add(std::vector<int>& lhs, std::vector<int>& rhs);

  BigInt operator=(const BigInt &other); 
  BigInt operator+(const BigInt &other) const;
  BigInt operator-(const BigInt &other) const;
  BigInt operator*(const BigInt &other) const;

};

} // namespace ds

#endif // __BIGINT_H__