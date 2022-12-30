#include<bits/stdc++.h>
using namespace std;


int f(int i,int j,vector<vector<int>> &dp)
{
    if(i==0 and j==0) return 1; //Base case
    if(i < 0 or j < 0) return 0; // Base Case

    if(dp[i][j] != -1) return dp[i][j]; //checking if it exist in dp array or not 

    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp); // Recursive approach

    return dp[i][j] = up + left; // Calculation Work
}


int uniquepaths(int m,int n) // Recursion + memorisation
{   
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return f(m-1,n-1,dp);
}


int uniquepaths(int m,int n,vector<int> &dp) // Tabulation 
{   
    // int dp[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0) dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }

    return dp[m-1][n-1];
}


int uniquepaths(int m,int n) // Space optimisation
{   
    vector<int> prev(n,-1);
    for(int i=0;i<m;i++)
    {   
        vector<int> temp(n,-1);
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0) temp[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }

    return prev[n-1];
}
int countWays(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return uniquepaths(m,n);
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquepaths(m,n);

    return 0;

}