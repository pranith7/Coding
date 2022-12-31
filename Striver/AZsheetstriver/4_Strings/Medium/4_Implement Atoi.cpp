#include<bits/stdc++.h>
using namespace std;


/*
    

The function myAtoi is a string parsing function that converts a string representation of an integer 
to an integer value. It handles several cases, such as leading whitespace characters, a leading plus 
or minus sign, and integer overflow.

The function first initializes a variable index to 0 and skips any leading whitespace characters by 
incrementing index until it points to a non-whitespace character or the end of the string. It 
then checks for a leading plus or minus sign and sets a boolean variable isNegative accordingly.

Next, the function enters a loop that runs until it reaches the end of the string or encounters a 
non-digit character. In each iteration, it converts the current character to an integer digit using 
the expression s[index] - '0', adds this digit to the current integer value by multiplying the current
 value by 10 and adding the digit, and increments index. It also checks for integer overflow by 
 comparing the current value to INT_MAX / 10 and to INT_MAX / 10 with the current digit added. If either
  condition is met, the function returns INT_MIN or INT_MAX depending on the value of isNegative.

Finally, the function returns the integer value, negated if isNegative is true.
*/
class Solution {
public:
  int myAtoi(string s) {
      
    const int len = s.size();

    if(len == 0){
        return 0;
    }

    int index = 0;

    // skipping white spaces
    while(index < len && s[index] == ' '){
        ++index;
    }

    // to handle sign cases
    bool isNegative = false;

    if(index < len){

      if(s[index] == '-'){
        isNegative = true;
        ++index;
      } else if (s[index] == '+'){
          ++index;
      }

    }

    int result = 0;

    // converting digit(in character form) to integer form
    // iterate until non-digit character is not found or we can say iterate till found character is a digit
    while(index < len && isDigit(s[index])){

      /* s[index] - '0' is to convert the char digit into int digit eg: '5' - '0' --> 5
      or else it will store the ASCII value of 5 i.e. 53,
      so we do 53(ASCII of 5) - 48(ASCII of 0(zero)) to get 5 as int*/
      int digit = s[index] - '0';

      // to avoid integer overflow
      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
          return isNegative ? INT_MIN : INT_MAX;
      }

      result = (result * 10) + digit; // adding digits at their desired place-value

      ++index;
    }
      
    return isNegative ? -result : result;
  }
    
private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};