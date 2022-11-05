#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int left=0,right=nums.size()-1;
    int minVal = INT_MAX;

    while (left <= right) {
        if (nums[left] < nums[right]) {
        minVal = min(minVal, nums[left]);
        break;
        }
    
        int mid = left + (right - left) / 2;

        if (nums[left] <= nums[mid]) {
        minVal = min(minVal, nums[left]);
        left = mid + 1;
        }

        else {
        minVal = min(minVal, nums[mid]);
        right = mid - 1;
        }
    }
        return nums[left]; 
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<findMin(nums);
    return 0;
}