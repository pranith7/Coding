#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> &nums)
{
      int n = nums.size();
        int k =0;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])   
                k++;
            else 
                nums[i-k] = nums[i];
        }
        return n-k;  
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
    remove_duplicates(arr);
    cout<<"output of the array"<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}