#include<bits/stdc++.h>
using namespace std;


/*
    This is a C++ class that contains a method splitArray() which uses a binary search algorithm to find 
    the minimum largest sum of a contiguous subarray of a given array of integers that can be split into
    a specified number of subarrays. The array is passed to the method as a vector of integers nums, and 
    the number of subarrays is specified by the parameter m.

    The method begins by defining the variables l, r, and n to represent the left and right bounds of the 
    search range and the length of the array, respectively. It then initializes l to the maximum value in
    the array, and r to the sum of all the values in the array.

    The method then enters a loop that continues until l is less than or equal to r. In each iteration of
    the loop, it calculates the midpoint between l and r and stores it in the variable mid. It then initializes
    the variables count and tempsum to 0 and iterates through the elements of the array.

    For each element, if adding it to tempsum does not exceed mid, the method adds it to tempsum. If adding
    it to tempsum does exceed mid, the method increments count by 1, sets tempsum to be the current element,
        and continues the loop.

    After all the elements have been processed, the method increments count by 1 to account for the final subarray.

    If count is less than or equal to m, the method updates r to be mid - 1 and sets the variable ans to be mid.
    If count is greater than m, the method updates l to be mid + 1 and continues the loop.

    Finally, when the loop ends, the method returns ans, which is the minimum largest sum of a contiguous subarray
    that can be split into the specified number of subarrays.
*/
class Solution {
public:
  
    int splitArray(vector<int>& nums, int m) {
      int l=0,r=0,n=nums.size();
        for(int i=0;i<n;++i) l=max(l,nums[i]), r+=nums[i];
        
        int mid=0,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            int count=0,tempsum=0;
            for(int i=0;i<n;++i){
                if(tempsum+nums[i]<=mid) tempsum+=nums[i];
                else count++,tempsum=nums[i];
            }
            count++; 
            
            if(count<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }  
        return ans;
    }
};