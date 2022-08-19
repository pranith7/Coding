#include <bits/stdc++.h> 
using namespace std;


void sort012(int *arr, int n)       //Dutch national flag algorithm
{
   //   Write your code here
    int low = 0,mid=0,high = n-1;
    while(mid<=high)
    {
        if(arr[mid] == 0)
        {    
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {    
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort012(arr,n);
    cout<<"Output sorted array "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}