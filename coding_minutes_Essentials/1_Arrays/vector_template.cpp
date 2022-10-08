#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr)
{
        
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<=arr.size()-1;i++)
        {
            cin>>arr[i];
        }
        solve(arr);
        for(int x : arr)
        {
            cout<<x<<" ";
        }
    }
    
    return 0;
}