#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{   
    bool var;
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {   
        var = false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
                var = true;
        }
    // IF no two elements were swapped
    // by inner loop, then break
    if(var == false) 
        break;
    }
    /*
        
    */
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
    bubble_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}