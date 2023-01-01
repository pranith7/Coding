#include <bits/stdc++.h>
using namespace std;

/*
    The cutRod function is a recursive function that calculates the maximum possible revenue that can be obtained by 
    cutting a rod of given length N and selling its pieces. The function takes in a vector of prices price where price[i] 
    denotes the price of a rod of length i+1. The function uses a memorization approach, where it stores the result of each 
    subproblem in a 2D table dp.

    The function first initializes the base case where the length of the rod is 1. In this case, the maximum possible revenue 
    is simply the price of the rod times the number of pieces.

    For the general case, the function calculates the maximum revenue by considering two possibilities: not taking the 
    current rod and taking the current rod. The function calculates the maximum revenue for each of these possibilities and 
    returns the maximum of the two. If the rod is not taken, then the maximum revenue is simply the maximum revenue obtained
    by cutting the rod of length N-1. If the rod is taken, then the maximum revenue is the price of the rod plus the maximum
    revenue obtained by cutting the rod of length N-rodLength, where rodLength is the length of the current rod. The function 
    stores the result of each subproblem in dp and returns the result of the subproblem represented by ind and N.

*/
int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){

    if(ind == 0){
        return N*price[0];
    }
    
    if(dp[ind][N]!=-1)
        return dp[ind][N];
        
    int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
    
    int taken = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N)
        taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
        
    return dp[ind][N] = max(notTaken,taken);
}


int cutRod(vector<int>& price,int N) { //Recursion + Memorisation

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    return cutRodUtil(price,N-1,N,dp);
}

int cutRod(vector<int>& price,int N) { //Tabulation

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    
    for(int i=0; i<=N; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];
}

// int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){

//     if(ind == 0){
//         return N*price[0];
//     }
    
//     if(dp[ind][N]!=-1)
//         return dp[ind][N];
        
//     int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
    
//     int taken = INT_MIN;
//     int rodLength = ind+1;
//     if(rodLength <= N)
//         taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
        
//     return dp[ind][N] = max(notTaken,taken);
// }


int cutRod(vector<int>& price,int N) { //space optimisation

    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
}


int main() {

  vector<int> price = {2,5,7,8,10};
  
  int n = price.size();
                                 
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}