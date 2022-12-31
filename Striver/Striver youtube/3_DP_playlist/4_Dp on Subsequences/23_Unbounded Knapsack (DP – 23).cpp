#include <bits/stdc++.h>
using namespace std;

/*
    The given code is implementing an unbounded knapsack problem using recursion and memorization. 
    The unbounded knapsack problem is a variation of the classical knapsack problem where we are allowed to 
    use items of the same type multiple times. The knapsack has a weight capacity W and we are given a set 
    of items each with a weight wt[i] and a value val[i]. The goal is to fill the knapsack with items such 
    that the total value is maximized without exceeding the weight capacity of the knapsack.

    The function knapsackUtil is a recursive function that takes in the following arguments:

    wt: A vector of size n representing the weights of the items
    val: A vector of size n representing the values of the items
    ind: An integer representing the current index in the wt and val vectors
    W: An integer representing the weight capacity of the knapsack
    dp: A 2D vector of size n x (W+1) used for memorization

    The function returns the maximum value that can be obtained from the items in the range [0, ind]
    such that the total weight does not exceed W.

    The function first checks if the current index is 0. If it is, it returns the value obtained by taking 
    all the items of the first type. This is because in the unbounded knapsack problem, we are allowed to 
    take as many items of the same type as we want.

    Next, the function checks if the value has already been calculated and stored in the dp vector. 
    If it has, it returns the value from the dp vector.

    The function then calculates the value obtained by not taking the current item by calling the function recursively 
    for the previous item (ind-1). It also calculates the value obtained by taking the current item by calling the function
    recursively for the current item with the updated weight capacity (W-wt[ind]). The function then returns the maximum of the two values.

    The function knapsack is the wrapper function that calls the knapsackUtil function with the initial arguments and returns the result. 
    It also initializes the dp vector with -1.

*/

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<int> cur(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        cur[i] = ((int)i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = cur[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
    }
    
    return cur[W];

}


int main() {

  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}
