#include<bits/stdc++.h>
using namespace std;

bool solve(int idx,int s,vector<int> &temp,int arr[],int n,int k)
{
    if(idx == n)
    {
        if(s == k)
        {
            for(int i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<" ";
            }
            return true;
        }
        return false;
    }

    temp.push_back(arr[idx]);
    s += arr[idx];
    if(solve(idx+1,s,temp,arr,n,k)) 
        return true;
    temp.pop_back();
    s -= arr[idx];
    if(solve(idx+1,s,temp,arr,n,k)) 
        return true;

    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        vector<int> temp;
        solve(0,0,temp,arr,n,k);
    }
    return 0;
}