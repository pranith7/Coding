#include<bits/stdc++.h>
using namespace std;


int sumOfMaxMin(int arr[], int n){
    int ma = arr[0];
    int mi = arr[0];
    for(int i=0;i<n;i++)
    {
        ma = max(ma,arr[i]);
        mi = min(mi,arr[i]);
    }
    
    return ma + mi;
}


int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x = sumOfMaxMin(arr,n);
    cout<<x<<" ";
    return 0;
}