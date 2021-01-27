#include "BigInt.h"
#include <iostream>
#include <string>

using namespace std;

ds::BigInt evaluatePostfix(const std::string &postfix);
std::string infixToPostfix(const std::string &infix);

int main(int argc, char *argv[]) {
  ds::BigInt a("456");
  ds::BigInt b("1123");

  ds::BigInt s = a + b;
  cout << s << endl;

  ds::BigInt d = a - b;
  cout << d << endl;

  ds::BigInt p = a * b;
  cout << p << endl;

  std::string postfix = infixToPostfix(" 2 * ( 456 + 1123 ) - 23582190 ");
  cout << postfix << endl;
  ds::BigInt r = evaluatePostfix(postfix);
  cout << r << endl;
}