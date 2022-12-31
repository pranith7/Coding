#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        The function beautySum takes in a string s and returns an integer value which is the sum
        of the absolute differences between the maximum and minimum frequency of characters in all 
        substrings of s having at least two characters.

        The function first initializes an integer array chars of size 123 to 0, which will be used to store 
        the frequency of each character in s. It also initializes a multiset ms and a temporary multiset tmpMs. 
        The multisets ms and tmpMs will be used to store the frequencies of characters in all substrings of s 
        having at least two characters.

        The function then calculates the frequency of each character in s and adds it to ms if it is not 0.

        The function then enters a loop which will run for all substrings of s having at least two characters. 
        Inside the loop, the function removes the character before the current index i from ms, if i is not 0. 
        It then enters another loop which will run for all substrings of s having at least two characters and 
        ending at the current index j. Inside this loop, the function removes the character after the current 
        index j, if j is not the last character of s. It then increases the value of res by the difference 
        between the maximum and minimum frequency in ms and restores the characters removed from ms.

        Finally, the function returns the value of res.
    */
    int beautySum(string s) {
        // support variables
        int res = 0, chars[123] = {};
        multiset<int> ms, tmpMs;
        // computing the frequencies of all the characters in s
        for (char c: s) chars[c]++;
        // populating ms initially
        for (int i = 'a'; i <= 'z'; i++) if (chars[i]) ms.insert(chars[i]);
        for (int i = 0, currFreq, lmtI = s.size() - 2, ed = s.size() - 1; i < lmtI; i++) {
            // removing the character before i, if any
            if (i) {
                currFreq = --chars[s[i - 1]];
                ms.erase(ms.find(currFreq + 1));
                if (currFreq) ms.insert(currFreq);
            }
            tmpMs = ms;
            for (int j = ed, lmtJ = i + 1; j > lmtJ; j--) {
                // removing the character before i, if any
                if (j != ed) {  
                    currFreq = --chars[s[j + 1]];
                    ms.erase(ms.find(currFreq + 1));
                    if (currFreq) ms.insert(currFreq);
                }
                // increasing res with the difference of extreme frequencies
                res += *rbegin(ms) - *begin(ms);
            }
            // restoring chars and ms
            for (int j = ed - 1, lmtJ = i + 1; j > lmtJ; j--) ++chars[s[j + 1]];
            ms = tmpMs;
        }
        return res;
    }
};