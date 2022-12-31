#include <bits/stdc++.h>
using namespace std;

/*
    The minSubsetSumDifference function is used to find the minimum difference between 
    the sum of two subsets of a given array arr of size n. The function first calculates the 
    total sum of all the elements in the array. It then initializes a 2D dynamic programming array 
    dp of size n by totSum + 1 with all elements initialized to -1.

    The function then loops through each value from 0 to totSum, calling the subsetSumUtil function 
    for each value. The subsetSumUtil function is a recursive function that takes in 4 arguments:

    ind: the index of the current element in the array
    target: the target sum
    arr: the input array
    dp: the dynamic programming array

    The subsetSumUtil function first checks if the target sum is 0, in which case it returns true. 
    It then checks if the current index ind is 0, in which case it returns true if the first element 
    in the array equals the target sum, and false otherwise. If the value of dp[ind][target] has already
    been computed, it simply returns the value.

    Otherwise, the function calculates two values: one where the current element is not taken, and
    one where it is taken. The value where the current element is not taken is obtained by calling 
    subsetSumUtil with the same target sum but with the current index decremented by 1. The value 
    where the current element is taken is obtained by calling subsetSumUtil with the target sum decremented
    by the value of the current element and with the current index decremented by 1, but only if the value
    of the current element is less than or equal to the target sum. The function then returns the OR of 
    these two values.

    After the loop ends, the minSubsetSumDifference function loops through each value from 0 to totSum and 
    checks if dp[n - 1][i] is true. If it is, the function calculates the difference between i and (totSum - i) 
    and updates the minimum difference if this difference is smaller than the current minimum difference. Finally,
    the function returns the minimum difference.
*/
bool subsetSumUtil(int ind, int target,vector<int> &arr, vector<vector<int>> &dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector < int > & arr, int n) { //Recursion + Memorisation

  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector<vector <int>> dp(n, vector <int> (totSum + 1, -1));

  for (int i = 0; i <= totSum; i++) {
    bool dummy = subsetSumUtil(n - 1, i, arr, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;

}

int minSubsetSumDifference(vector < int > & arr, int n) { //Tabulation
  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < bool >> dp(n, vector < bool > (totSum + 1, false));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  if (arr[0] <= totSum)
    dp[0][totSum] = true;

  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= totSum; target++) {

      bool notTaken = dp[ind - 1][target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = dp[ind - 1][target - arr[ind]];

      dp[ind][target] = notTaken || taken;
    }
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}

int minSubsetSumDifference(vector < int > & arr, int n) { //space optimisation
  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < bool > prev(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    vector < bool > cur(totSum + 1, false);
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}

int main() {

  vector<int> arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);
}