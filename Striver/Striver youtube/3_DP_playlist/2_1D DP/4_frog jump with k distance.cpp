#include<bits/stdc++.h>
using namespace std;

int frog_jump(vector<int> &arr,int k)
{
    vector<int> dp(arr.size(),0);
    dp[0] = 0;
    for(int i=1;i<arr.size();i++)
    {   
        int min_steps = INT_MAX;
        for(int j=1;j<k;j++)
        {
            if(i-j >= 0)
            {
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                min_steps = min(min_steps,jump);
            }
        }
        dp[i] = min_steps;
    }
    return dp[arr.size()-1];
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<frog_jump(arr,k);
    return 0;
}