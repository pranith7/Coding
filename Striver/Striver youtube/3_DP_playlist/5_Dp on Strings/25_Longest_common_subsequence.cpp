#include <bits/stdc++.h>
using namespace std;


/*
    The given code is an implementation of the Longest Common Subsequence (LCS) problem using recursion and memorization.

LCS is a well-known problem in computer science that consists in finding the longest subsequence that is common to two
given sequences. In this case, the given function receives two strings s1 and s2, and it returns the length of the longest
common subsequence between them.

The solution uses a recursive approach with memorization, which means that the function keeps track of the solutions 
for subproblems that have already been solved. This way, the function avoids recalculating those solutions, which reduces
the overall time complexity of the algorithm.

The function works as follows:

It checks if either of the indices ind1 or ind2 is negative. If either of them is, it returns 0, as there are no more characters to compare.
If the solution for the subproblem defined by ind1 and ind2 has already been calculated and stored in the dp array, it returns the stored value.

If the characters at positions ind1 and ind2 in s1 and s2 respectively are the same, the function adds 1 to the length of 
the LCS found so far and calls itself recursively with indices ind1-1 and ind2-1. This means that the function continues 
searching for a common subsequence by considering the characters before the current ones.

If the characters are different, the function returns the maximum value between the LCS found by considering the character at
position ind1 in s1 and ignoring the character at position ind2 in s2, and the LCS found by considering the character at 
position ind2 in s2 and ignoring the character at position ind1 in s1. This means that the function chooses the path that 
leads to the longest common subsequence.


Finally, the function stores the result in the dp array and returns it.

*/
int lcsUtil(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){

    if(ind1<0 || ind2<0)
        return 0;
        
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1,s2,ind1-1,ind2-1,dp);
    
    else 
        return dp[ind1][ind2] = 0 + max(lcsUtil(s1,s2,ind1,ind2-1,dp),lcsUtil
       (s1,s2,ind1-1,ind2,dp));
   
}


int lcs(string s1, string s2) { //Recursion + Memorisation
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return lcsUtil(s1,s2,n-1,m-1,dp);
}

int lcs(string s1, string s2) { // Tabulation
    
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

int lcs(string s1, string s2) { // Space optimisation
    
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

int main() {

  string s1= "acd";
  string s2= "ced";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2)<<endl;
}