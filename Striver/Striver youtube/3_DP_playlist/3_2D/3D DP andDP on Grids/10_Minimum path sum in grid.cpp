#include <bits/stdc++.h>
using namespace std;

/*
    The minSumPath function is a recursive function that computes the minimum sum path from the top
    left of a matrix to the bottom right. It uses dynamic programming by storing the results in a 
    2D array dp to avoid re-computing the same subproblems.

The function takes in 3 parameters:

n: the number of rows in the matrix
m: the number of columns in the matrix
matrix: the matrix of integers
It returns an integer, which is the minimum sum of the path from the top left to the bottom right of the matrix.

The function first checks if it has reached the top left element of the matrix (base case). If it has, it 
returns the value of that element. If it has not, it checks if the current row or column is out of bounds. 
If it is, it returns a large number (1e9). This is done to prevent the function from going out of bounds and
crashing.

The function then checks if the value of dp[i][j] has already been computed. If it has, it returns that value. 
If not, it calculates the minimum sum path by adding the current element in the matrix to the minimum of the sum
 of the path coming from the top and the sum of the path coming from the left. It stores this result in dp[i][j]
  and returns it.
*/

int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;

  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
  int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);
  
  return dp[i][j] = min(up,left);
  
}

int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return minSumPathUtil(n-1,m-1,matrix,dp);
    
}

int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
return dp[n-1][m-1];
    
}

int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix);
}
