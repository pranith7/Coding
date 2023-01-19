#include <iostream>
#include <unordered_map>
using namespace std;


/*
    This code uses a sliding window approach to solve the problem of finding the longest substring 
    without repeating characters in a given string. It uses an unordered_map to keep track of the 
    last seen position of each character in the current substring. The variable start keeps track 
    of the start of the current substring. The for loop iterates through each character in the 
    string, and the if statement checks if the current character has been seen before and if it was
    seen after the start of the current substring. If so, the start pointer is moved to the position
    after the last seen position of that character. The if statement updates the maxLength and maxStart
    variables if a longer substring without repeating characters is found. Finally, the function returns
    the substring using the maxStart and maxLength values.
*/
string longestSubstringWithoutRepeatingChars(string s) {
    unordered_map<char, int> charLastSeen;
    int start = 0, maxLength = 0, maxStart = 0;
    for (int end = 0; end < s.length(); end++) {
        if (charLastSeen.find(s[end]) != charLastSeen.end() && charLastSeen[s[end]] >= start) {
            start = charLastSeen[s[end]] + 1;
        }
        charLastSeen[s[end]] = end;
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            maxStart = start;
        }
    }
    return s.substr(maxStart, maxLength);
}

int main() {
    string s = "abcdabcdefgh";
    cout << longestSubstringWithoutRepeatingChars(s);
    return 0;
}
