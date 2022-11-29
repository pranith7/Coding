/*

Shortcut:-
1. Try to represent the problem in terms of index
2. Do all possible tuffs on that index according to the problem statement
3. Sum of all stuffs -> count all ways
   min(of all stuffs) -> find min

*/
#include<bits/stdc++.h>
using namespace std;


int main() {  // tabulation

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}



int stairs(int idx)
{
    if(idx == 0) return 1;
    if(idx == 1) return 1;

    int left = stairs(idx - 1);
    int right = stairs(idx-2);

    return left + right;
}

int main()
{
    int n;
    cin>>n;
    cout<<stairs(n);
    return 0;
}