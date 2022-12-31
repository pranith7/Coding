#include<bits/stdc++.h>
using namespace std;

/*
In the given code, the function f is used to find the number of unique paths in a maze with obstacles. It takes in four arguments:

i: the row index of the current position
j: the column index of the current position
mat: a 2D vector representing the maze, where -1 represents an obstacle and 0 represents a valid cell
dp: a 2D vector used for memorization of the result of previously calculated positions

The function first checks if the current position is an obstacle or not. If it is, it returns 0. 
If not, it then checks if the current position is the starting position (0,0). If it is, it returns 1. 
If not, it checks if the current position is outside the maze. If it is, it returns 0.

If none of the above conditions are satisfied, the function checks if the result for the current
position has been previously calculated and stored in the dp array. If it has, it returns the stored result. 
If not, it calculates the result by adding the number of unique paths from the cell above and the number of 
unique paths from the cell to the left. It then stores the result in the dp array and returns it.

The Mazeobstacles function takes in three arguments: the number of rows m, the number of columns n, and the 
2D vector representing the maze mat. It initializes an empty 2D vector dp of size m x n and calls the f
*/

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