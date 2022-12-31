#include <bits/stdc++.h>
using namespace std;


/*
    The knapsackUtil function is a recursive function that solves the knapsack problem using the top-down approach 
    with memorization. The function takes four parameters:

    wt: a vector of integers representing the weights of each item
    val:a vector of integers representing the values of each item
    ind:an integer representing the index of the current item
    W:  an integer representing the maximum weight that the knapsack can hold
    dp: a 2D vector of integers that is used for memorization. It stores the maximum value that 
        can be obtained for a given index ind and maximum weight W.

The function first checks if the ind is 0, which is the base case. If it is, it checks if the weight
 of the first item is less than or equal to the maximum weight that the knapsack can hold. If it is,
  it returns the value of the first item. Otherwise, it returns 0.

If ind is not 0, the function checks if the value of dp[ind][W] is already calculated. If it is, 
it returns the value of dp[ind][W]. Otherwise, it calculates the maximum value that can be obtained 
by either not taking the current item or by taking the current item. It stores the maximum value in dp[ind][W] and returns it.

*/
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){ //Recursion + Memorisation
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){ //Tabulation
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){ //2row space optimisation
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0), cur(W+1,0);
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
        prev = cur;
    }
    
    return prev[W];
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){ //1row space optimisation
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0);
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=w; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
        // prev = cur;
    }
    
    return prev[W];
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}