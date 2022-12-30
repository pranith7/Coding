#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp)
{   
    if(i >= 0 and j >= 0 and mat[i][j] == -1) return 0; //Checking if obstacle exists
    if(i==0 and j==0) return 1; //Base case
    if(i < 0 or j < 0) return 0; // Base Case

    if(dp[i][j] != -1) return dp[i][j]; //checking if it exist in dp array or not 

    int up = f(i-1,j,mat,dp);
    int left = f(i,j-1,mat,dp); // Recursive approach

    return dp[i][j] = up + left; // Calculation Work
}


int Mazeobstacles(int m,int n,vector<vector<int>> & mat)  // Recursion + Memorisation
{
     vector<vector<int>> dp(m,vector<int> (n,0));
    return f(m-1,n-1,mat,dp);
}

int Mazeobstacles(int m,int n,vector<vector<int>> & mat)  // Tabulation
{
    int dp[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0) dp[i][j] = 1;
            else if(mat[i][j] == -1) dp[i][j] = 0; //Checking if obstacle exists
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

int mod = int(1e9 + 7);

int Mazeobstacles(int m,int n,vector<vector<int>> & mat)  // Space optimisation
{
    vector<int> prev(n,0);
    for(int i=0;i<m;i++)
    {   
        vector<int> cur(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0) cur[j] = 1;
            else if(mat[i][j] == -1) cur[j] = 0; //Checking if obstacle exists
            else
            {
                int up = 0;
                int left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                cur[j] = (up + left)%mod;
            }
        }
        prev = cur;
    }

    return prev[n-1];   
}





int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int> (n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];

    cout<<Mazeobstacles(m,n,mat);

    return 0;
}