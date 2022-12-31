#include<bits/stdc++.h>
using namespace std;

/*
    This code is a solution to a problem where the task is to find the maximum depth of 
    nested parentheses in a given string.

    The solution iterates through the string and maintains a counter called "depth" to keep 
    track of the current depth of nested parentheses. Whenever an open parenthesis '(' is encountered, 
    the depth is incremented by 1. Whenever a closed parenthesis ')' is encountered, the depth 
    is decremented by 1. The maximum depth seen so far is stored in a variable called "res".

    After iterating through the entire string, the final value of "res" is returned as the 
    result. This is the maximum depth of nested parentheses found in the string.

    For example, if the input string is "( ( ( ) ) )", the depth would be incremented by 1 each time 
    an open parenthesis is encountered, and decremented by 1 each time a closed parenthesis is encountered. 
    This would result in a final value of "res" equal to 3, which is the maximum depth of nested parentheses in the string.
*/
class Solution {
public:
    int maxDepth(string s) {
      int res = 0;
        int depth = 0;
        for(int i =0 ; i < s.size(); ++i)
        {
             if(s[i] == '(')
                ++depth;
            else if(s[i] == ')')
                --depth;
            res = max(depth, res);
        }
    return res;   
    }
};