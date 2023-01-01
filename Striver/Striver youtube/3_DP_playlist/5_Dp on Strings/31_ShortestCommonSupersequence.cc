#include <bits/stdc++.h>
using namespace std;

/*
    This function finds the shortest supersequence of two strings s1 and s2, which is a string that contains 
    both s1 and s2 as subsequences. It does so by first initializing a two-dimensional dynamic programming (DP) 
    table dp with n+1 rows and m+1 columns, where n is the length of s1 and m is the length of s2. The function
     then sets the value of the first row and column of the table to 0.

    The function then iterates through each character in s1 and s2 and fills out the DP table by comparing each
    character and setting the value at the current index to the value at the index immediately above and to the
    left if the characters are equal, or to 0 plus the maximum value of the cells directly above or to the left 
    of it if the characters are not equal.

    The function then backtracks through the DP table to find the shortest supersequence by appending either the
    character from s1 or s2 to the ans string, depending on which cell has the larger value. Finally, the function
    reverses the ans string and returns it.
*/

string shortestSupersequence(string s1, string s2){

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string ans = "";

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans += s1[i-1];
      index--;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans += s1[i-1];
        i--;
    } else {
        ans += s2[j-1];
        j--;
    }
  }
  
  //Adding Remaing Characters - Only one of the below two while loops will run 
  
  while(i>0){
      ans += s1[i-1];
      i--;
  }
  while(j>0){
      ans += s2[j-1];
      j--;
  }

  reverse(ans.begin(),ans.end());
  
  return ans;
}

int main() {

  string s1 = "brute";
  string s2 = "groot";

  cout << "The Longest Common Supersequence is "<<shortestSupersequence(s1,s2)<<endl;
}