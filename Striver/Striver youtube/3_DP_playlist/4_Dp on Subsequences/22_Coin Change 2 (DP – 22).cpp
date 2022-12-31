#include <bits/stdc++.h>
using namespace std;


/*
    The given function is a recursive implementation to count the number of ways to make change for a given 
    amount T using given denominations of coins. It uses a 2D array dp for memorization to store the intermediate 
    results and avoid re-computation.

    The function first checks if the base case has been reached i.e. if the current index ind is 0. If it is, 
    it checks if the target amount T can be achieved using the given denomination arr[0]. 
    If it can, it 
                returns 1, 
            else it 
                returns 0.

    If the base case has not been reached, the function checks if the value of dp[ind][T] has already been calculated and stored. 
    If it has, it returns that value.

    If the value of dp[ind][T] has not been calculated before, the function calculates it by considering two cases - one where the
    current denomination arr[ind] is not taken and one where it is taken. In the first case, the function calls itself for ind-1 and T. 
    In the second case, it calls itself for ind and T-arr[ind]. The number of ways to make change for the given amount in both cases is 
    added and stored in dp[ind][T]. The function then returns dp[ind][T].

    The function countWaysToMakeChange is the wrapper function that initializes the dp array and calls countWaysToMakeChangeUtil for 
    the given values of arr, n, and T.
*/
long countWaysToMakeChangeUtil(vector<int>& arr,int ind, int T, vector<vector<long>>& dp){ 

    if(ind == 0){
        return (T%arr[0]==0);
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    
    long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}


long countWaysToMakeChange(vector<int>& arr, int n, int T){ //Recursion + Memorisation
    
    vector<vector<long>> dp(n,vector<long>(T+1,-1));
    return countWaysToMakeChangeUtil(arr,n-1, T, dp);
}

long countWaysToMakeChange(vector<int>& arr, int n, int T){ // Tabulation   
    vector<vector<long>> dp(n,vector<long>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
}

long countWaysToMakeChange(vector<int>& arr, int n, int T){ // Space optimisation
    
    vector<long> prev(T+1,0);
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as prev array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = cur[target-arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
}

int main() {

  vector<int> arr ={1,2,3};
  int target=4;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}