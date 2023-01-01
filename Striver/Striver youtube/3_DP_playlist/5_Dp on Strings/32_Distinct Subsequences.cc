#include<bits/stdc++.h>
using namespace std;

/*
    This function computes the number of ways that the string s can be obtained as a subsequence of the string t. 
    It does so by using a combination of recursion and memoization.

    The function first initializes a two-dimensional DP table dp with lt rows and ls columns. It then calls the 
    helper function countUtil, which uses recursion to fill out the DP table by comparing each character in t 
    and s and setting the value at the current index to the sum of the values at the indices immediately above
    and to the left if the characters are equal, or to the value at the index immediately above if the characters
    are not equal. The function then returns the value at the bottom-right cell of the DP table, which is the number
    of ways that s can be obtained as a subsequence of t.

    The prime variable is used to take the modulo of the result to avoid integer overflow. The % operator computes
    the remainder of the division of the number on its left by the number on its right. In this case, prime is set
    to a large prime number, so taking the modulo of the result with prime will not affect the result in any 
    significant way, but it will prevent integer overflow.
*/
int prime = 1e9+7;

int countUtil(string s1, string s2, int ind1, int ind2,vector<vector<int>>& dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2]){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay)%prime;
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls) { //Recursion + Memorisation
    // Write your code here.
    
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return countUtil(t,s,lt-1,ls-1,dp);
} 

int subsequenceCounting(string &s1, string &s2, int n, int m) { //Tabulation
    // Write your code here.
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][m];
} 

int subsequenceCounting(string &s1, string &s2, int n, int m) { //space optimisation
    // Write your code here.
    
    vector<int> prev(m+1,0);
    
    prev[0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--){ // Reverse direction
            
            if(s1[i-1]==s2[j-1])
                prev[j] = (prev[j-1] + prev[j])%prime;
            else
                prev[j] = prev[j]; //can omit this statemwnt
        }
    }
    
    
    return prev[m];
} 

int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout << "The Count of Distinct Subsequences is "
  <<subsequenceCounting(s1,s2,s1.size(),s2.size());
}