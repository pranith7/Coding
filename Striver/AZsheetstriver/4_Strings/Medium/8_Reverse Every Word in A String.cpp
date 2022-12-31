#include <bits/stdc++.h>
using namespace std;

/*
        The reverseWords function takes a string s as input and returns a string which 
        is the reverse of the words in s.

        The function first initializes an empty stack and an empty string result. It then iterates 
        through the characters in s using a for loop. If a character is a space, the loop skips it 
        and moves on to the next character. If the character is not a space, the function stores the
        continuous sequence of letters into a string word. Once the loop encounters a space or reaches
        the end of the string, it pushes word onto the stack.

        After the for loop completes, the function pops the elements from the stack and appends them
        to result separated by a space until the stack is empty. Finally, the function returns result.
*/
class Solution {

    public:
        string reverseWords(string s) {
                if(s.size() == 0) return s;
                stack<string> stack;
                string result;
                for(int i=0; i<s.size(); i++) {
                    string word;
                    if(s[i]==' ') continue; //skip spaces
                    while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                        word += s[i]; i++;
                    }
                    stack.push(word); //push word to the stack
                }
                while(!stack.empty()) {
                    result += stack.top(); stack.pop();
                    if(!stack.empty()) result += " ";
                }
                return result;
            }
};