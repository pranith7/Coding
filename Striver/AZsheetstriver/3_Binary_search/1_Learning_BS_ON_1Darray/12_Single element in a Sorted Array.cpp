#include<bits/stdc++.h>
using namespace std;


 int singleNonDuplicate(vector<int>& nums) {
        /*
            This function is a solution to the problem of finding the non-duplicate element in a sorted 
            array of integers where every element appears twice, except for one element which appears only
            once.

            The function takes a vector of integers called nums as input and returns an integer.

            The function uses a binary search algorithm to find the non-duplicate element. The algorithm 
            works by dividing the array into halves and determining which half the non-duplicate element 
            is in by comparing the elements at the middle index and its neighbors. If the middle element 
            is equal to the element to its left or right, depending on whether the middle index is even or 
            odd, then the non-duplicate element must be in the other half of the array. The algorithm 
            continues to divide the array and compare elements until it finds the non-duplicate element.

            The variables left and right are used to keep track of the bounds of the current half of the 
            array being searched. The variable mid is used to store the middle index of the current half of
             the array. The while loop continues until left is no longer less than right, at which point the
              non-duplicate element will have been found and left will be pointing at its index. The function
               then returns the element at this index.
        */
	     int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<singleNonDuplicate(nums);
    return 0;
}