#include <bits/stdc++.h>
using namespace std;

/*
    The minimumElements function is a recursive function that takes in a vector arr of integers, a target integer T,
     and a dp array as input. It uses a recursive approach to find the minimum number of elements from the given array
      that can sum up to the given target T.

    The function has a base case where, if the index ind is equal to 0 (meaning the function has reached the first element of the array), 
    it checks if the target T can be achieved by using only the first element. If T is divisible by the first element, it returns 
    T divided by the first element. Otherwise, it returns a very large number to indicate that the target cannot be achieved using 
    only the first element.

    For other cases, the function checks if the element at the current index ind is less than or equal to the target T. If it is, 
    it adds 1 to the recursive call that does not include the current element and uses the remaining target T - arr[ind]. If the element 
    at the current index is not less than or equal to the target, it only makes the recursive call that does not include the current element. 
    Finally, it returns the minimum of the two recursive calls, which is stored in the dp array at the index [ind][T] for future use.

    The minimumElements function returns the value stored in the dp array at index [n-1][T], which is the minimum number of elements 
    required to achieve
*/

int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(ind == 0){
        if(T%arr[0] == 0) return T/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
    int taken = 1e9;
    if(arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = min(notTaken,taken);
}


int minimumElements(vector<int>& arr, int T){ //Recursion + Memorisation
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, T, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int minimumElements(vector<int>& arr, int T){ //Tabulation
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

int minimumElements(vector<int>& arr, int T){ //Space optimisation
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}
int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}