#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    int key;
    for(int i=1;i<n;i++)                        
    {
        key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
    
        }
        arr[j+1] = key;
    }
    /*
        5 4 3 2 1   -> key = 4 [updation of line l8]
        -- 5 5 3 2 1 -> 4 5 3 2 1 
        4 5 3 2 1 -> key = 3
         -- 4 5 5 2 1 -- 4 4 5 2 1 --> 3 4 5 2 1 [Updation of line 18]
        3 4 5 2 1 -> key = 2
        	-- 3 4 5 2 1 -- 3 4 5 5 1  -- 3 4 4 5 1 -- 3 3 4 5 1 --> 2 3 4 5 1[updation of line 18]
        2 3 4 5 1 -> key = 1
            -- 2 3 4 5 1 -- 2 3 4 5 5 -- 2 3 4 4 5 -- 2 3 3 4 5 -- 2 2 3 4 5 -> 1 2 3 4 5
            

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
    insertion_sort(arr);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}