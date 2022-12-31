#include <bits/stdc++.h>
using namespace std;

/*
    The function findWays is a function that takes in a vector of integers num and an integer k and
    returns the number of ways to sum the elements of the vector num to get k.

The function first declares and initializes a two-dimensional vector dp with n rows and k+1 columns 
and fills it with -1. dp[i][j] represents the number of ways to sum the elements in num from index 0 to i to get j.

The function then calls the helper function findWaysUtil which takes in four arguments: ind, target, arr, and dp. 
ind represents the current index in the arr vector, target represents the target sum, arr is the input vector and
 dp is the two-dimensional vector that stores the solutions to the subproblems.

The function has two base cases:

If ind is 0, then the function checks if target is 0 and arr[0] is 0 or if target is equal to arr[0]. 
If either of these conditions is true, the function returns 1, otherwise it returns 0.
If target is 0, the function returns 1.
If the value of dp[ind][target] has already been calculated, the function returns that value.

Otherwise, the function calculates the number of ways to get the target sum by not taking the element at index ind and 
by taking the element at index ind. It stores the result in dp[ind][target] and returns it.
*/

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {

  vector<int> arr = {0,0,1};
  int k=1;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}

#include <bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int countPartitions(int d, vector<int>& arr){ //Recursion + Memorisation
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}

int findWays(vector<int> &num, int tar){ // Tabulation
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int findWays(vector<int> &num, int tar){ //space optimisation
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);
}


int main() {

  vector<int> arr = {5,2,6,4};
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(d,arr);
}