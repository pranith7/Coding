#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        int x = nums.size()/3;
        // if(x < 3) return nums;
        for(int i=0;i<nums.size();i++)
        {
           m[nums[i]]++;
        }

        for(auto i : m)
        {
            if(i.second > x)
            {
               ans.push_back(i.first);
            }

        }
        return ans;
        
    }
};