#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N ^ 2)
    Space complexity: O(N ^ 2)

    Where N is the number of rows (or columns) of the square matrix.
*/

int findMaxValue(vector<vector<int>>& mat, int n) {
    int maxVal = INT_MIN;

    // Declare n * n matrix to store the states
    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = mat[0][0];

    // Find dp for first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], mat[i][0]);
    }

    // Find dp for first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = min(dp[0][j - 1], mat[0][j]);
    }

    // Find dp for all cells other than first row and column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            maxVal = max(maxVal, mat[i][j] - dp[i - 1][j - 1]);
            dp[i][j] = min(mat[i][j], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    // Return the maximum value
    return maxVal;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin>>mat[i][j];
    }
    int ans = findMaxValue(mat,n);
    cout<<ans<<endl;
    return 0;
}