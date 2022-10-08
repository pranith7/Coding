#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
    for(int i=1;i<=n-1;i++)
    {
        int cur = a[i];
        int prev = i-1;
        while(prev>=0 && a[prev]>cur)
        {
            a[prev + 1] = a[prev];
            prev = prev -1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr, n);
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<",";
    }
    return 0;
}