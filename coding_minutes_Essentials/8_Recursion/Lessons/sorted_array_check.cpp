#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr,int n)
{
    //Base case
    if(n==1 or n==0)
        return true;
    if(arr[n-1]>arr[n-2] and solve(arr,n-1))
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(arr,n);
    return 0;
}