#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int i,int n) 
{
    if(i>=n/2) return; //Base case 
    swap(arr[i],arr[n-i-1]); //calculation work
    reverseArray(arr,i+1,n); // recursion approach
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
    reverseArray(arr,0,n);
    cout<<"the output array is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}