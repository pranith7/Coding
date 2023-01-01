#include <bits/stdc++.h>
using namespace std;

/*
    This function computes the length of the longest common subsequence (LCS) of two strings s1 and s2. 
    It does so by first initializing a two-dimensional dynamic programming (DP) table dp with n+1 rows
    and m+1 columns, where n is the length of s1 and m is the length of s2. The function then sets the 
    value of the first row and column of the table to 0.

    The function then iterates through each character in s1 and s2 and fills out the DP table by comparing
    each character and setting the value at the current index to the value at the index immediately above 
    and to the left if the characters are equal, or to 0 plus the maximum value of the cells directly above
    or to the left of it if the characters are not equal.

    At the end, the function returns the value at the bottom-right cell of the DP table, which is the 
    length of the LCS. This method of dynamic programming is known as tabulation.
*/
int lcs(string s1, string s2) { //Tabulation
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}
int lcs(string s1, string s2) { //space optimisation
    
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int main() {

  string s= "bbabcbcab";
                                 
  cout<<"The Length of Longest Palindromic Subsequence is "<<
  longestPalindromeSubsequence(s);
}