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
    // count number of subarrays with given xor k
    /*
        The given code is a solution to a problem that asks to count the number of subarrays 
        in a given array A with a given xor B.

        The solution uses an unordered map visited to store the number of times a particular xor
        value has been encountered so far. The variable cpx keeps track of the xor value of the 
        elements from the start of the array up to the current index i. If cpx is equal to B, we 
        increment the count c by 1, as this indicates that the xor of the elements from the start
        of the array up to index i is equal to B.

        We then check if the value h (which is equal to cpx xor B) is present in the visited map. 
        If it is, we add the number of times h has been encountered to c. Finally, we increment 
        the count of cpx in the visited map by 1.

The function returns the total count c of subarrays with xor B at the end.
    */
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