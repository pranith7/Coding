#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &arr)
{
    int n = arr.size();
    
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
    merge_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}