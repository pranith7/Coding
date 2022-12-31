#include <bits/stdc++.h>
using namespace std;

/*
    The above code is an implementation of the subset sum problem using recursion and memorization. 
    The subsetSumToK() function takes in three arguments:

    n: an integer representing the number of elements in the input array arr.
    k: an integer representing the target sum that we want to check if it can be achieved by 
    selecting some elements from arr.
    arr: a vector of integers representing the input array.

The subsetSumUtil() function is a helper function that is used to recursively check if 
the target sum can be achieved by selecting some elements from the given array arr. 

It takes in four arguments:

ind:    an integer representing the current index in the array arr.
target: an integer representing the target sum that we want to check if it can be achieved 
        by selecting some elements from arr.
arr:    a reference to the input array arr.
dp:     a reference to a 2D vector that is used for storing the intermediate results.

The base cases for the recursion are when the target sum is 0 or the current index is 0. 
If the target sum is 0, it means that we have achieved the target sum and we return true. 
If the current index is 0, it means that we have reached the end of the array and we return 
true only if the element at index 0 is equal to the target sum.

If the result for the current index and target sum is present in the dp array, we return that value.
Otherwise, we calculate the result by checking if the element at the current index is included or not
included in the sum. If the element is not included, we recursively call the function with the next index 
and the same target sum. If the element is included, we recursively call the function with the next index
and the target sum reduced by the value of the element at the current index. The final result is the OR of
the two recursive calls. The result is also stored in the dp array for future reference.

The subsetSumToK() function first initializes the dp array with -1 and then calls the subsetSumUtil() function 
with the last index of the array and the target sum. The result returned by the subsetSumUtil() function is then
returned by the subsetSumToK() function.
*/

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind == 0)  return arr[0] == target;
    
    if(dp[ind][target]!=-1)  return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target] = notTaken || taken;
}

bool subsetSumToK(int n, int k, vector<int> &arr){ //Recursion + Memorsiation
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    return subsetSumUtil(n-1,k,arr,dp);
}

bool subsetSumToK(int n, int k, vector<int> &arr){ //Tabulation
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr){ //space optimisation
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}


int main() {

  vector<int> arr = {1,2,3,4};
  int k=4;
  int n = arr.size();
                                 
  if(subsetSumToK(n,k,arr))
    cout<<"Subset with given target found";
  else 
    cout<<"Subset with given target not found";
}