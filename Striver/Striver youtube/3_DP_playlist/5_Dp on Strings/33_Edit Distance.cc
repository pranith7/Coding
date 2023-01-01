#include <bits/stdc++.h>
using namespace std;

/*
    This function computes the minimum number of operations required to transform the string S1 
    into the string S2. It does so by using a combination of recursion and memoization.

    The function first initializes a two-dimensional DP table dp with n rows and m columns, 
    where n is the length of S1 and m is the length of S2. It then calls the helper function 
    editDistanceUtil, which uses recursion to fill out the DP table by comparing each character
    in S1 and S2 and setting the value at the current index to the minimum of the values at the
    indices immediately above and to the left and the value at the index immediately above if the
    characters are not equal, or to 0 if the characters are equal. The function then returns the 
    value at the bottom-right cell of the DP table, which is the minimum number of operations 
    required to transform S1 into S2.

    The three operations that can be performed are:

    Insert a character into S1
    Delete a character from S1
    Replace a character in S1 with a different character

    The function uses the min function to find the minimum of three values. The min function returns
    the smaller of the two values passed to it as arguments.
*/

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    // Minimum of three choices
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}

int editDistance(string& S1, string& S2){// Recursion + Memorisation
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return editDistanceUtil(S1,S2,n-1,m-1,dp);
    
}


int editDistance(string& S1, string& S2){ // Tabulation 
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
}

int editDistance(string& S1, string& S2){ //space optimisation
    
    int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                cur[j] = 0+prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev = cur;
    }
    
    return prev[m];
    
}
    
int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}