#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n)
{
    for(int pos=0;pos<=n-2;pos++)
    {   
        int cur = a[pos];
        int min_pos = pos;
        for(int j=pos;j<n;j++)
        {
            if(a[j]<a[min_pos])
            {
                min_pos = j;
            }
        }
        swap(cur,a[min_pos]);
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
    selection_sort(arr, n);
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<",";
    }
    return 0;
}