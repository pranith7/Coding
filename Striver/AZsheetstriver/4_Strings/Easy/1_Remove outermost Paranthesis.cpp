#include<bits/stdc++.h>
using namespace std;

/*
        This is a C++ class that contains a method removeOuterParentheses() which removes the outermost 
        parentheses from a string of parentheses. The string is passed to the method as a parameter S.

        The method declares a string res to store the modified string, and an integer opened to keep track 
        of the number of open parentheses encountered so far. It then iterates through the characters in S 
        using a range-based for loop.

        For each character c in S, the method checks if c is an open parenthesis. If it is, it increments 
        opened and appends c to res if opened is greater than 0. This ensures that the first open parenthesis
        is not added to res.

        The method then checks if c is a closed parenthesis. If it is, it decrements opened and appends c 
        to res if opened is greater than 1. This ensures that the final closed parenthesis is not added to res.

        Finally, the method returns res, which is the modified string with the outermost parentheses removed.
*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;       
    }
};