#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
        
}

void display(int arr[],int n)
{
        cout<<"output of the array is"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        solve(arr,n);
        display(arr,n);
    }
    
    return 0;
}