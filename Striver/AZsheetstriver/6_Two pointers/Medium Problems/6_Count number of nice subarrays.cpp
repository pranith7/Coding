#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0,end = 0,oddcount = 0,evencount = 0,count = 0;
        while(end<n)
        {
            while(end<n and oddcount < k) {
                if(nums[end++]%2) oddcount++;
            }
            evencount =1;
            while(end<n and nums[end]%2==0)
            {
                evencount++;
                end++;
            }
            while(start < n and oddcount == k){
                count += evencount;
                if(nums[start++]%2) --oddcount;
            }

        }
        return count;
    }
};