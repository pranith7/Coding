#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int times = 1;times<=n-1;times++)
    {
        for(int j=0;j<=n-1-times;j++)
        {
            if(a[j]>a[j+1]) 
            {
                swap(a[j],a[j+1]);
            }   
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
    bubble_sort(arr, n);
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<",";
    }
    return 0;
}