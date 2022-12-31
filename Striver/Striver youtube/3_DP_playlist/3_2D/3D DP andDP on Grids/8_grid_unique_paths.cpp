#include<bits/stdc++.h>
using namespace std;

/*
    The given code defines a function "uniquepaths" which takes in two integer arguments
    "m" and "n" and returns an integer value. This function is used to find the total number
    of unique paths from the top-left corner to the bottom-right corner of a grid with "m" rows and "n" columns.

    The function first declares a 2D vector "dp" with "m" rows and "n" columns, initialized with -1. 
    This vector is used to store the results of subproblems, to avoid recalculating them.

    The function then calls another function "f", which takes in 3 arguments: an integer "i" 
    representing the row number, an integer "j" representing the column number, and a reference to
    the 2D vector "dp". This function returns the total number of unique paths from the top-left corner (0,0)
    to the cell (i,j).

    The function "f" has two base cases:

    If "i" and "j" are both 0, it means we have reached the top-left corner, so the function returns 1.
    If either "i" or "j" is negative, it means we have moved out of the grid, so the function returns 0.
    If the result for the subproblem (i,j) is already present in the "dp" vector, the function returns that value. 
    Otherwise, it calculates the number of unique paths to (i,j) by adding the number of paths from (i-1,j) and (i,j-1). 
    It then stores this result in the "dp" vector and returns it.

    Finally, the "uniquepaths" function returns the result of the function "f" called with the arguments (m-1,n-1) 
    and the 2D vector "dp". This gives the total number of unique paths from the top-left corner (0,0) to the 
    bottom-right corner (m-1,n-1) of the grid.


*/
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