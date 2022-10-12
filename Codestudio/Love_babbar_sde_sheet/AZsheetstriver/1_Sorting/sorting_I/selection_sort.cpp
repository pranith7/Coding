#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < arr.size(); j++)
        {
            if(arr[j] < arr[min_idx]) min_idx = j;

        }
        if(min_idx!=i)  swap(arr[min_idx], arr[i]);
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}