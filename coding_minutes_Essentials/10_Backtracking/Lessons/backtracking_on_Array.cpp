#include<bits/stdc++.h>
using namespace std;



void solve(int *arr,int i,int n,int val)
{
    //Base case
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    arr[i] = val;
    solve(arr,i+1,n,val+1);
    arr[i] = -arr[i];
}

int main()
{   
    int n;
    cin>>n;
    int arr[n+2] = {0};
    solve(arr,0,n,1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}