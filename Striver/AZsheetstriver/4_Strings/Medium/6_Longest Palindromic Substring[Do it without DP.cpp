#include<bits/stdc++.h>
using namespace std;

/*
    The given longestPalindrome function is a solution to the problem of finding the longest palindrome
    substring in a given string. It uses dynamic programming to solve the problem.

    The function first initializes a 2D bool array dp with all elements set to false. Then it sets every
    single character in the string to be a palindrome, by setting the corresponding element in dp to true. 
    This is done by setting dp[i][i] = true for all i from 0 to n-1, where n is the length of the string.

    Then, the function iterates through the string in reverse order, and for each character, it checks all the 
    characters that come after it. If the current character and the character being compared are the same, then 
    it checks if the substring between them is a palindrome. This is done by checking if the substring has only 
    two characters (in which case it is automatically a palindrome), or if the substring with the current characters
    removed is a palindrome. If either of these conditions is true, then the current substring is also a palindrome,
    and the corresponding element in dp is set to true.

    Finally, the function checks for the longest palindrome substring by iterating through dp and finding the longest
    substring for which dp[i][j] is true. The function returns this substring.

*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};