#include <iostream>
#include <unordered_map>
using namespace std;

/*
    This code uses a sliding window approach to solve the problem of finding the longest 
    substring with k unique characters in a given string. It uses an unordered_map to keep 
    track of the frequency of each character in the current substring, and two pointers 
    (start and end) to keep track of the current substring. The variable uniqueChars keeps
    track of the number of unique characters in the current substring. The while loop 
    ensures that the number of unique characters in the current substring does not exceed
    k, and the if statement updates the maxLength and maxStart variables if a longer 
    substring with k unique characters is found. Finally, the function returns the substring using the maxStart and maxLength values.
*/

string longestSubstringWithKUniqueChars(string s, int k) {
    unordered_map<char, int> charFrequency;
    int start = 0, maxLength = 0, maxStart = 0, uniqueChars = 0;
    for (int end = 0; end < s.length(); end++) {
        charFrequency[s[end]]++;
        if (charFrequency[s[end]] == 1) {
            uniqueChars++;
        }
        while (uniqueChars > k) {
            charFrequency[s[start]]--;
            if (charFrequency[s[start]] == 0) {
                uniqueChars--;
            }
            start++;
        }
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            maxStart = start;
        }
    }
    return s.substr(maxStart, maxLength);
}

/*
    This code uses a sliding window approach similar to the previous solution. It uses a 
    hash table (unordered_map) to keep track of the frequency of each character in the 
    current substring. The while loop ensures that the number of unique characters in the 
    current substring does not exceed k by moving the start pointer to the right. If the 
    frequency of a character becomes zero, it is removed from the hash table. The if 
    statement updates the maxLength and maxStart variables if a longer substring with k 
    unique characters is found. Finally, the function returns the substring using the maxStart and maxLength values.
*/
string longestSubstringWithKUniqueChars(string s, int k) {
    unordered_map<char, int> charFrequency;
    int start = 0, maxLength = 0, maxStart = 0;
    for (int end = 0; end < s.length(); end++) {
        charFrequency[s[end]]++;
        while (charFrequency.size() > k) {
            if (--charFrequency[s[start]] == 0) {
                charFrequency.erase(s[start]);
            }
            start++;
        }
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            maxStart = start;
        }
    }
    return s.substr(maxStart, maxLength);
}


int main() {
    string s = "abaccc";
    int k = 2;
    cout << longestSubstringWithKUniqueChars(s, k);
    return 0;
}
