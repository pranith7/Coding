#include <bits/stdc++.h>
using namespace std;

/*
        This function computes the length of the longest common subsequence (LCS) of two strings s1 and s2. 
        It does so by first initializing a two-dimensional dynamic programming (DP) table dp with n+1 rows 
        and m+1 columns, where n is the length of s1 and m is the length of s2.

        The function then iterates through each character in s1 and s2 and fills out the DP table by comparing each 
        character and setting the value at the current index to the value at the index immediately above and to the 
        left if the characters are equal, or to 0 if they are not equal. The function also keeps track of the maximum 
        value in the table, which is the length of the LCS.

        At the end, the function returns this maximum value, which is the length of the LCS.
*/

int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
    
}

int lcs(string &s1, string &s2){ //space optimisation
	//	Write your code here.
    
    int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0), cur(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    
    return ans;
    
}
int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}
