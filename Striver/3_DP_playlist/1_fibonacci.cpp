/*
    Memorization technique is to solve the problem of sub-problems or overlapping sub problems and it is top-down approach.
    which is used in the below code which is an extension of recursion using fibonacii
    and stored the results of particular sub-problems in a dp array to make time complextiy better.

    Tebulation is also a technique of dynamic programming and it is bottom up approach.

    Time complexity  is O(n)
    Space complexity  is O(n)[stack size] + o(n)[dp array]
*/


#include<bits/stdc++.h>
using namespace std;

int func(int n,vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n] = func(n-1,dp) + func(n-2,dp);   
}

int main()
{   
    int n;
    cin>>n;

    // vector<int> dp(n+1,-1);
    // cout<<func(n,dp);
    /*

       tabulation

    */
    int prev2 = 0;
    int prev1 = 1;
    for(int i=2;i<=n;i++)
    {
        int curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }
    
    cout<<prev1;
    return 0;
}