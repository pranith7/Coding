#include<bits/stdc++.h>
using namespace std;

void left_rotate_array_by_D(vector<int> &nums,int k)
{
           int n = nums.size();
           k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            reverse(nums.begin(),nums.begin()+n-k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            reverse(nums.begin() + n - k, nums.begin() + n);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(nums.begin(), nums.end());
}

int main()
{
    int n,D;
    cin>>n,D;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    left_rotate_array_by_D(arr,D);
    cout<<"output of the array"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
    return 0;
}