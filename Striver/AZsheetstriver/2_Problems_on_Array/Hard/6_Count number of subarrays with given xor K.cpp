#include<bits/stdc++.h>
using namespace std;


int subsetXOR(int arr[], int n, int k)
{
    // Find maximum element in arr[]
    int max_ele = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_ele)
            max_ele = arr[i];

    // Maximum possible XOR value
    int m = (1 << (int)(log2(max_ele) + 1)) - 1;
    if (k > m)
        return 0;
    // The value of dp[i][j] is the number of subsets having
    // XOR of their elements as j from the set arr[0...i-1]
    int dp[n + 1][m + 1];

    // Initializing all the values of dp[i][j] as 0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;

    // The xor of empty subset is 0
    dp[0][0] = 1;

    // Fill the dp table
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j]
                = dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]];

    //  The answer is the number of subset from set
    //  arr[0..n-1] having XOR of elements as k
    return dp[n][k];
}

class Solution{
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
};


int main()
{   vector<int> A{ 4,2,2,6,4 };
    Solution obj;
    int totalCount= obj.solve(A,6);
    cout<<"The total number of subarrays having a given XOR k is "<<totalCount<<endl;
}