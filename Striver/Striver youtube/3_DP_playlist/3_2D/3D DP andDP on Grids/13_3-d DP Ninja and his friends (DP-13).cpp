#include<bits/stdc++.h>
using namespace std;
/*
      This function is a recursive implementation of a solution to a problem where you are given a 
      2D grid of integers representing a staircase, and you can start from the top of the staircase 
      and move down to the bottom either by jumping one step to the right or one step to the left at 
      a time. The goal is to maximize the sum of the integers you collect along the way by choosing 
      the optimal path.

      The function takes in the following parameters:

      i: an integer representing the current row index (starting from 0)
      j1: an integer representing the current column index of the first step (starting from 0)
      j2: an integer representing the current column index of the second step (starting from 0)
      n: an integer representing the number of rows in the grid
      m: an integer representing the number of columns in the grid
      grid: a 2D vector of integers representing the staircase
      dp: a 3D vector of integers representing the memory table for storing the results of previously computed subproblems
      It returns an integer representing the maximum sum of integers that can be collected along the optimal path from the top to the bottom of the staircase.

      The function first checks if the current column indices for the first and second steps are out of bounds. If either 
      of them is, it returns a large negative integer (-1e9).

      If the current row index (i) is the last row (n-1), it checks if the two steps are in the same column. 
      If they are, it returns the value in that column. If they are not, it returns the sum of the values in 
      both columns.

      if the result of function maximumChocolates has not been calculated before, the function 
      calls itself recursively with the updated indices i+1, j1+di, j2+dj. The function then returns
      the maximum value of all these recursive calls, which represents the maximum number of chocolates that can
      be collected from that particular position. This value is then stored in the dp array for future reference,
      so that if the function is called again with the same indices, it can directly return the result from the dp 
      array, rather than recalculating it through recursive calls. This technique is known as memorization and it 
      helps to avoid recalculating the result for the same indices, thus improving the efficiency of the function. 
      Once the function has reached the last row, it returns the maximum number of chocolates that can be collected 
      from that position, which is the value of either the cell at grid[i][j1] or the sum of the values of the cells
      at grid[i][j1] and grid[i][j2], depending on whether the indices j1 and j2 are equal or not.
      
*/
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) { //Recursion + Memorisation

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}


int maximumChocolates(int n, int m, vector < vector < int >> & grid) { //Tabulation
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) { //space optimisation
  // Write your code here.
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];

}

int main() {

   vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}