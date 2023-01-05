#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long profit,op1,op2;
    
    if(buy==0){// We can buy the stock
        op1 = 0+getAns(Arr,ind+1,0,n,dp); 
        op2 = -Arr[ind] + getAns(Arr,ind+1,1,n,dp);
    }
    
    if(buy==1){// We can sell the stock
        op1 = 0 + getAns(Arr,ind+1,1,n,dp), 
        op2 = Arr[ind] + getAns(Arr,ind+1,0,n,dp);
    }
    profit = max(op1,op2);
    return dp[ind][buy] = profit;
}


long getMaximumProfit(long *Arr, int n) //Recursion + Memorisation
{
    //Write your code here
    
    vector<vector<long>> dp(n,vector<long>(2,-1));
    
    if(n==0) return 0;
    long ans = getAns(Arr,0,0,n,dp);
    return ans;
}
long getMaximumProfit(long *Arr, int n) //Tabulation
{
    //Write your code here
    
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    
    //base condition
    dp[n][0] = dp[n][1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];
}

long getMaximumProfit(long *Arr, int n) //space optimisation
{
    //Write your code here
    
    vector<long> ahead (2,0);
    vector<long> cur(2,0);
    
    //base condition
    ahead[0] = ahead[1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+ahead[0], -Arr[ind] + ahead[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy]  = profit;
        }
        
        ahead = cur;
    }
    return cur[0];
}
int main() {

  int n =6;
  long Arr[n] = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<getMaximumProfit(Arr, n);
}