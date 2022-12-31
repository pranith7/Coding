#include <bits/stdc++.h>
using namespace std;

/*
    The function findWays is a recursive function that uses dynamic programming to find the number of ways to sum up to 
    a target number k using the elements in the array num. The function first checks if the target has already been reached,
    in which case it returns 1. If the target has not been reached and there are no more elements left in the array, the 
    function returns 0. If the target has not been reached and there are still elements left in the array, the function checks
    if the current element arr[ind] can be included in the sum. If it can be included, the function recursively calls itself with 
    the updated target as target-arr[ind]. If the current element cannot be included, the function simply recursively calls itself 
    with the same target. The function uses a 2D dynamic programming array dp to store the intermediate results and avoid recalculating 
    the same subproblems. The function returns the sum of the number of ways to include the current element and the number of ways to 
    not include the current element.
*/
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){ //Recursion + memorisation
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int findWays(vector<int> &num, int k){ //Tabulation
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    
    if(num[0]<=k)
        dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][k];
    
}
int findWays(vector<int> &num, int k){ //space optimisation
    int n = num.size();

    vector<int> prev(k+1,0);
    
    prev[0] =1;
    
    if(num[0]<=k)
        prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= notTaken + taken;
        }
        
        prev = cur;
    }
    
    return prev[k];

    
}
int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}