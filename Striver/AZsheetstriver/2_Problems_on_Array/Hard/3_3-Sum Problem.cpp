#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //3sum problem
        /*
            The threeSum function is a member function of the Solution class that returns all unique 
            triplets of integers in a given array that sum to zero.

            The function takes a reference to a vector of integers nums as input and returns a 
            two-dimensional vector of integers a. It first checks if the size of nums is less than
            3 and returns an empty vector a if it is. It then sorts the elements of nums in ascending
            order.

            The function then enters a loop that iterates over the elements of nums, starting from the
            first element and ending at the second-to-last element. In each iteration, it checks if the 
            current element is greater than 0 and breaks out of the loop if it is, since all the remaining
            elements will also be greater than 0. It also checks if the current element is equal to the 
            previous element and continues to the next iteration if it is, to avoid adding duplicate 
            triplets to a.

            The function then initializes two variables, left and right, to the indices of the second
            and last elements of nums, respectively. It then enters a loop that continues until left is
            equal to or greater than right. In each iteration, it calculates the sum of the current element,
             the element at index left, and the element at index right. If the sum is less than 0, it increments 
             left by 1. If the sum is greater than 0, it decrements right by 1. If the sum is equal to 0, it 
             pushes a triplet containing the current element, the element at index left, and the element at 
             index right into a, and increments left and decrements right by 1. It also skips over any consecutive
         duplicate elements at indices left and right using two nested while loops.

            Finally, the function returns a.
        */
        vector<vector<int>> a;
        if(nums.size()<3) return a;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i)
        {
            if(nums[i]>0) break;
            if(i>0 and nums[i] == nums[i-1]) continue;
            int left = i+1,right = n - 1;
            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum<0) ++left;
                else if(sum>0) --right;
                else
                {
                    a.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left+1] == nums[left]) ++left;
                    while(left<right && nums[right-1] == nums[right]) --right;
                    left++;
                    right--;
                }
            }
        }
        return a;
    }
};