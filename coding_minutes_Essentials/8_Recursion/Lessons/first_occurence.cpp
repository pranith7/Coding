#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n,int key)
{   
    //Base case
    if(n==0)
        return -1;
    if(arr[0] == key )
        return 0;
    //Recursive approach
    int subindex = solve(arr+1,n-1,key);
    if(subindex!=-1)
        return subindex+1;

    return -1;
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n,key;
        cin>>n>>key;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n,key);
        // display(arr,n);
    }
    
    return 0;
}