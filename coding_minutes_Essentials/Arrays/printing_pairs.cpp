#include<bits/stdc++.h>
using namespace std;

void printing_pairs(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int x = arr[i];
        for(int j=i+1;j<n;j++)
        {
            int y = arr[j];
            cout<<"Pairs are "<<x<<" "<<y<<endl;
        }
    }
}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printing_pairs(arr,n);
    cout<<"output of the array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}