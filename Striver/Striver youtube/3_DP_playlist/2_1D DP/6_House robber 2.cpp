#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentsum(vector<int> &nums) // Tabulation --> space optimisation
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;
        int nottake = 0 + prev;
        int  curi = max(take,nottake);
        prev2 = prev;
        prev = curi;

    }
    return prev;
}

long long int solve(vector<int> &arr)
{   
    int n = arr.size();
    vector<int> temp1,temp2;
    if(n==1) return arr[0];
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            temp1.push_back(arr[i]);
        if(i!=n-1)
            temp2.push_back(arr[i]);
    }
    return max(maximumNonAdjacentsum(temp1),maximumNonAdjacentsum(temp2));
}

int main()
{
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(arr);
    return 0;
}