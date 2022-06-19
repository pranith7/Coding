#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int i,int val)
{   
    //Base case
    if(i==arr.size())
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //
    arr[i] = val;
    solve(arr,i+1,val+1);
    arr[i] = -arr[i];

}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        solve(arr,0,1);
        for(int x : arr) cout<<x<<" ";
    }
    
    return 0;
}