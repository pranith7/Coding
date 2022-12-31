#include <bits/stdc++.h>
using namespace std;

/*
    In the above code, the minimumPathSum function is a recursive function that takes in a triangle 
    represented as a 2D vector and the number of rows in the triangle as input. It returns the minimum
    sum of the path from the top of the triangle to the bottom. The function makes use of another helper 
    function, minimumPathSumUtil, which takes in the current row and column indices, the triangle, the number
    of rows in the triangle, and a 2D dp array as input. The dp array is used to store the results of 
    subproblems to avoid recalculating them.

    The minimumPathSumUtil function first checks if the current subproblem has already been solved and 
    stored in the dp array. If it has, it returns the stored value. If not, it checks if it has reached 
    the last row of the triangle. If it has, it returns the value at the current cell in the triangle. 
    Otherwise, it calculates the minimum path sum by recursively calling the function for the cell below 
    and the cell below-right and returning the minimum of those two values. The result is then stored in 
    the dp array and returned.

    The minimumPathSum function then calls the minimumPathSumUtil function with the indices of the top cell 
    of the triangle, the triangle, and the number of rows in the triangle as input, and returns the result. 
    This allows the minimumPathSumUtil function to calculate the minimum path sum starting from the top of 
    the triangle and working its way down to the bottom.
    
*/
int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, vector<vector<int> > &dp) 
{
  
  if(dp[i][j]!=-1)  return dp[i][j]; // Checknig if it exists or not  
  if(i==n-1) return triangle[i][j]; //Base case
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}

int minimumPathSum(vector<vector<int> > &triangle, int n){ // Recursion + Memorisation
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return minimumPathSumUtil(0,0,triangle,n,dp);
    
}
int minimumPathSum(vector<vector<int> > &triangle, int n){ //Tabulation
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}

int minimumPathSum(vector<vector<int> > &triangle, int n){ //space optimisation
    vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    
    return front[0];
    
}


int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}