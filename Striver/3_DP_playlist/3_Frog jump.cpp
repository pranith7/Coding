#include<bits/stdc++.h>
using namespace std;



// int f(int n,vector<int> &heights,vector<int> &dp)
/* Memorisation */
int f(int n,vector<int> &heights,vector<int> &dp)
{
    if(n == 0) return 0;
    if(dp[n]!=-1) return dp[n]; // checking if it exists or not 
    
    int left = f(n - 1, heights,dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if(n>1) 
    {
        right = f(n - 2, heights,dp) + abs(heights[n] - heights[n - 2]); // right
    }
    if(left < right) return dp[n] = left;
    return dp[n] = right;
       
} 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
   vector<int> dp(n+1,-1);
   return f(n-1,heights,dp);
}

/* tabulation*/
int frogJump_2(int n, vector<int> &heights)
{
    // Write your code here.
   vector<int> dp(n,0);
   dp[0] = 0;
   for(int i=1;i<n;i++)
   {
      int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
      int ss = INT_MAX;
      if(i>1)
        ss =  dp[i-2] + abs(heights[i] - heights[i-2]);
      dp[i] = min(fs,ss); 
   }
   return dp[n-1];
} 

/* space optimisation*/
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    int curi = INT_MAX;
    for(int i = 1;i<n;i++)
    {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = prev2 + abs(heights[i]-heights[i-2]);
        curi = min(fs,ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{   
    int n;
    cin>>n;
    vector<int> heights;
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<frogJump(n, heights);

    return 0;
}