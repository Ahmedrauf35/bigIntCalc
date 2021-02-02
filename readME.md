This was a class project for Data Structures, code that was written by me is mostly in BigInt.cpp and calculator.cpp.
Purpose of this project is to incorporate a BigInt class to allow representations (and arithmetic) of numbers bigger than the max limit of normal Ints (or long int, long long int etc). This implementation's purpose is similiar to that of the class already present in Java, although much more limited. (See https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/math/BigInteger.html) 
In BigInt.cpp,you can see my overloaded operators =,+,-, and * .
These are then utilized in calculator.cpp. In this file, you can see several helper functions, mainly aiding in order of operations. Before evaluating the input, there is also a check for valid input (similar to https://leetcode.com/problems/valid-parentheses/), and converting the expression from infix notation to postfix notation. 
Once done, the program then evaluates the expression, which can include any of the overloaded operators and returns the answer.
Although you do see CMAKE and Docker files, they are not made by me. 
->However, I do have experience and some knowledge with running docker environments and the commmands required, thanks to this class.
And of course, Git; this is my first own repository! 
