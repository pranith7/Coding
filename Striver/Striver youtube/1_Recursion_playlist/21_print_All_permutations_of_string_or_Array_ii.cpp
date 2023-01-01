#include<bits/stdc++.h>
using namespace std;

/*
    The given function is a recursive function that finds all the permutations of a given vector of integers. 
    It does so by iterating over the elements of the given vector and swapping them with the current element 
    at each step. It then recursively calls itself with the modified vector and appends the current permutation
    to the final result.

    The function takes in a vector of integers nums and a vector of vectors of integers ans which will store
    all the permutations. It also takes an integer idx which indicates the current index in the vector.

    The function first checks if the idx is equal to the size of the nums vector. If it is, it means that all
    the elements in the vector have been considered, so it adds the current permutation to the result and returns.

    If idx is not equal to the size of nums, the function iterates over the elements of the vector from idx to the
    end and swaps the current element with the element at index idx. It then recursively calls itself with the
    modified vector and the index idx + 1, and finally swaps the elements back to their original positions.

    This process is repeated until all the permutations have been considered and added to the result. The function 
    then returns the final result.
*/
class Solution {
private:
    void solve(int idx,vector<int> &nums,vector<vector<int>> &ans)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i<nums.size();i++)
        { 
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};