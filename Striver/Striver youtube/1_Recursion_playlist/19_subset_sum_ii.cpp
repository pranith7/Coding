#include<bits/stdc++.h>
using namespace std;


/*

The given code is a solution to the problem of finding all the unique subsets of a given set.

The function solve is a recursive function that generates all the unique subsets of the given set. 

It takes four arguments:

idx: an integer representing the current index in the input set nums.
nums: a vector of integers representing the input set.
temp: a vector of integers representing the current subset being considered.
ans: a vector of vectors of integers representing the set of all unique subsets.
The function works as follows:

It first adds the current subset temp to the ans vector.
It then iterates over the elements in the input set nums starting from the index idx. For each element, 
it checks if it is a duplicate of the previous element. If it is a duplicate, it skips it.
If the element is not a duplicate, it adds it to the temp vector and calls the function recursively 
with the updated temp vector and the index i+1.
After the recursive call returns, it removes the element from the temp vector.
The function continues this process until all elements in the input set have been considered.
Finally, the function returns the ans vector, which contains all the unique subsets of the input set.

*/
class{
private:
    void solve(int idx,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;    
    }
};